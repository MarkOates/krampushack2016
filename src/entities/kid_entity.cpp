


#include <entities/kid_entity.h>

#include <cmath>



KidEntity::KidEntity(ElementID *parent, SpriteSheet *sprite_sheet, Shader *flat_color_shader, float x, float y, std::string name, behavior_t behavior)
   : EntityBase(parent, "kid", x, y)
   , name(name)
   , walk_speed(5.0)
   , flat_color_shader(flat_color_shader)
   , behavior(behavior)
   , identity_reveal_counter(0.0)
{
   place.size = vec2d(60, 30);
   bitmap.bitmap(sprite_sheet->get_sprite(random_int(0, 16)));
   bitmap.align(0.5, 1.0);
   bitmap.scale(2.0, 2.0);

   set("bound_in_world");
}



KidEntity::~KidEntity()
{
}



void KidEntity::reveal_identity()
{
   identity_reveal_counter = 0.0;
}



void KidEntity::update()
{
   identity_reveal_counter += 1.0 / 60.0;
   place += velocity;
}



void KidEntity::draw()
{
   ALLEGRO_COLOR identity_color = get_identity_color();
   float tint_intensity = get_identity_tint_intensity();

   flat_color_shader->use();

   flat_color_shader->set_vec3("tint", identity_color.r, identity_color.g, identity_color.b);
   flat_color_shader->set_float("tint_intensity", tint_intensity);
   EntityBase::draw();

   flat_color_shader->stop();
}



void KidEntity::stand_still()
{
   velocity.position = vec2d(0.0, 0.0);
}



void KidEntity::walk_up()
{
   velocity.position = vec2d(0.0, -walk_speed/2);
}



void KidEntity::walk_down()
{
   velocity.position = vec2d(0.0, walk_speed/2);
}



void KidEntity::walk_left()
{
   velocity.position = vec2d(-walk_speed, 0.0);
}



void KidEntity::walk_right()
{
   velocity.position = vec2d(walk_speed, 0.0);
}



ALLEGRO_COLOR KidEntity::get_identity_color()
{
   ALLEGRO_COLOR identity_color;

   switch(behavior)
   {
   case BEHAVIOR_ADULT:
      identity_color = color::gray;
      break;
   case BEHAVIOR_NAUGHTY:
      identity_color = color::firebrick;
      break;
   case BEHAVIOR_NICE:
      identity_color = color::white;
      break;
   }

   return identity_color;
}



float KidEntity::get_identity_tint_intensity()
{
   float strobe_speed = 3.0;
   float identiy_reveal_duration = 4.0;

   switch (behavior)
   {
   case BEHAVIOR_ADULT:
      return 1.0 - std::min(identity_reveal_counter*(1.0/identiy_reveal_duration), 1.0);
      break;
   case BEHAVIOR_NAUGHTY:
      strobe_speed = 3.0;
      break;
   case BEHAVIOR_NICE:
      strobe_speed = 1.0;
      break;
   }

   float normalized_oscilation = sin(al_get_time() * strobe_speed*4) * 0.5 + 0.5;
   float tint_intensity = 1.0 - std::min(identity_reveal_counter*(1.0/identiy_reveal_duration), 1.0);

   return normalized_oscilation * interpolator::fast_in(tint_intensity);
}



