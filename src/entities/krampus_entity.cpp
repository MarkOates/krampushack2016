


#include <entities/krampus_entity.h>

#include <factories/entity_factory.h>
#include <cmath>



KrampusEntity::KrampusEntity(ElementID *parent, SpriteSheet *sprite_sheet, float x, float y)
   : EntityBase(parent, "krampus", x, y)
   , state_is_busy(false)
   , walking_speed(5.0)
   , facing_right(true)
   , _has_weapon(false)
   , state(STANDING)
   , sprite_sheet(sprite_sheet)
{
   place.size = vec2d(120, 30);
   bitmap.bitmap(sprite_sheet->get_sprite(18));
   bitmap.align(0.5, 1.0);
   bitmap.scale(2.0, 2.0);

   set("bound_in_world");
}



KrampusEntity::~KrampusEntity()
{
}



void KrampusEntity::update()
{
   float previous_state_counter = state_counter;
   state_counter += 1.0 / 60.0;
   place += velocity;

   switch(state)
   {
   case STANDING:
      break;
   case ATTACKING:
      {
         float scale = 2.0;
         if (state_counter*scale >= 0.4 && previous_state_counter*scale < 0.4) bitmap.bitmap(sprite_sheet->get_sprite(20));
         if (state_counter*scale >= 0.5 && previous_state_counter*scale < 0.5)
         {
            bitmap.bitmap(sprite_sheet->get_sprite(21));

            float dh = place.h;
            float dy = place.y;
            float dw = 80;
            float dx = facing_right ? place.x + place.w : place.x - place.w;
            if (has_weapon()) EntityFactory::create_krampus_attack_damage_zone_with_club(get_parent(), dx, dy, dw, dh);
            else EntityFactory::create_krampus_attack_damage_zone(get_parent(), dx, dy, dw, dh);
         }
         if (state_counter*scale >= 0.7 && previous_state_counter*scale < 0.7) bitmap.bitmap(sprite_sheet->get_sprite(22));
         if (state_counter*scale >= 1.0 && previous_state_counter*scale < 1.0) set_state(STANDING, true);
         break;
      }
   case CELEBRATING:
      {
         float previous_state_counter_modded = std::fmod(previous_state_counter, 0.4);
         float state_counter_modded = std::fmod(state_counter, 0.4);
         float scale = 1.0;
         if (state_counter_modded*scale >= 0.1 && previous_state_counter_modded*scale < 0.1) bitmap.bitmap(sprite_sheet->get_sprite(19));
         if (state_counter_modded*scale >= 0.3 && previous_state_counter_modded*scale < 0.3) bitmap.bitmap(sprite_sheet->get_sprite(18));
      }
      break;
   default:
      break;
   }
}



void KrampusEntity::draw()
{
   place.start_transform();
   bitmap.position(place.size.x/2, place.size.y/2);
   bitmap.draw();
   place.restore_transform();
}



void KrampusEntity::attack()
{
   set_state(ATTACKING);
}



void KrampusEntity::stand_still()
{
   set_state(STANDING);
}



void KrampusEntity::walk_up()
{
   set_state(WALKING_UP);
}



void KrampusEntity::walk_down()
{
   set_state(WALKING_DOWN);
}



void KrampusEntity::walk_left()
{
   set_state(WALKING_LEFT);
}



void KrampusEntity::walk_right()
{
   set_state(WALKING_RIGHT);
}



void KrampusEntity::face_left()
{
   facing_right = false;
   bitmap.flags(ALLEGRO_FLIP_HORIZONTAL);
}



void KrampusEntity::face_right()
{
   facing_right = true;
   bitmap.flags(ALLEGRO_FLAGS_EMPTY);
}



void KrampusEntity::celebrate()
{
   set_state(CELEBRATING);
}



bool KrampusEntity::set_state(state_t new_state, bool override_if_busy)
{
   if (override_if_busy) state_is_busy = false;

   if (state_is_busy) return false;

   state_counter = 0.0;
   state = new_state;

   switch(new_state)
   {
   case WALKING_UP:
      bitmap.bitmap(sprite_sheet->get_sprite(18));
      velocity.position = vec2d(0.0, -walking_speed/2);
      break;
   case WALKING_DOWN:
      bitmap.bitmap(sprite_sheet->get_sprite(18));
      velocity.position = vec2d(0.0, walking_speed/2);
      break;
   case WALKING_LEFT:
      bitmap.bitmap(sprite_sheet->get_sprite(18));
      face_left();
      velocity.position = vec2d(-walking_speed, 0.0);
      break;
   case WALKING_RIGHT:
      bitmap.bitmap(sprite_sheet->get_sprite(18));
      face_right();
      velocity.position = vec2d(walking_speed, 0.0);
      break;
   case STANDING:
      bitmap.bitmap(sprite_sheet->get_sprite(18));
      velocity.position = vec2d(0.0, 0.0);
      break;
   case ATTACKING:
      state_is_busy = true;
      bitmap.bitmap(sprite_sheet->get_sprite(19));
      velocity.position = vec2d(0.0, 0.0);
      break;
   case CELEBRATING:
      bitmap.bitmap(sprite_sheet->get_sprite(19));
      velocity.position = vec2d(0.0, 0.0);
   default:
      return false;
      break;
   }

   return true;
}



void KrampusEntity::get_weapon()
{
   _has_weapon = true;
}



bool KrampusEntity::is_idle()
{
   return state == STANDING;
}



bool KrampusEntity::has_weapon()
{
   return _has_weapon;
}



