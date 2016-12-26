


#include <entities/kid_entity.h>



KidEntity::KidEntity(ElementID *parent, SpriteSheet *sprite_sheet, Shader *flat_color_shader, float x, float y, std::string name, behavior_t behavior)
   : EntityBase(parent, "kid", x, y)
   , name(name)
   , flat_color_shader(flat_color_shader)
   , behavior(behavior)
   , identity_counter(0.0)
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
   identity_counter = 0.0;
}



void KidEntity::update()
{
   identity_counter += 1.0 / 60.0;
}



void KidEntity::draw()
{
   ALLEGRO_COLOR identity_color = get_identity_color();
   float tint_intensity = 1.0 - std::min(identity_counter*0.25, 1.0);

   flat_color_shader->use();

   flat_color_shader->set_vec3("tint", identity_color.r, identity_color.g, identity_color.b);
   flat_color_shader->set_float("tint_intensity", tint_intensity);
   EntityBase::draw();

   flat_color_shader->stop();
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
      identity_color = color::red;
      break;
   case BEHAVIOR_NICE:
      identity_color = color::white;
      break;
   }

   return identity_color;
}



