


#include <entities/krampus_entity.h>
#include <factories/entity_factory.h>



KrampusEntity::KrampusEntity(ElementID *parent, SpriteSheet *sprite_sheet, float x, float y)
   : EntityBase(parent, "krampus", x, y)
   , state_is_busy(false)
   , facing_right(true)
   , state(STANDING)
   , sprite_sheet(sprite_sheet)
{
   place.size = vec2d(120, 30);
   bitmap.bitmap(sprite_sheet->get_sprite(18));
   bitmap.align(0.5, 1.0);
   bitmap.scale(2.0, 2.0);
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
         if (state_counter >= 0.4 && previous_state_counter < 0.4) bitmap.bitmap(sprite_sheet->get_sprite(20));
         if (state_counter >= 0.5 && previous_state_counter < 0.5)
         {
            bitmap.bitmap(sprite_sheet->get_sprite(21));
            EntityFactory::create_krampus_attack_damage_zone(get_parent(),
                 place.x+place.w, place.y-30, 80, place.y);
         }
         if (state_counter >= 0.7 && previous_state_counter < 0.7) bitmap.bitmap(sprite_sheet->get_sprite(22));
         if (state_counter >= 1.0 && previous_state_counter < 1.0) set_state(STANDING, true);
         break;
      }
   default:
      break;
   }
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
      velocity.position = vec2d(0.0, -1.0);
      break;
   case WALKING_DOWN:
      bitmap.bitmap(sprite_sheet->get_sprite(18));
      velocity.position = vec2d(0.0, 1.0);
      break;
   case WALKING_LEFT:
      bitmap.bitmap(sprite_sheet->get_sprite(18));
      face_left();
      velocity.position = vec2d(-2.0, 0.0);
      break;
   case WALKING_RIGHT:
      bitmap.bitmap(sprite_sheet->get_sprite(18));
      face_right();
      velocity.position = vec2d(2.0, 0.0);
      break;
   case STANDING:
      bitmap.bitmap(sprite_sheet->get_sprite(18));
      velocity.position = vec2d(0.0, 0.0);
      break;
   case ATTACKING:
      state_is_busy = true;
      bitmap.bitmap(sprite_sheet->get_sprite(19));
      velocity.position = vec2d(0.0, 0.0);
   default:
      return false;
      break;
   }

   return true;
}



