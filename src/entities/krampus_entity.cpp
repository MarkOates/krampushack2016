


#include <entities/krampus_entity.h>



KrampusEntity::KrampusEntity(ElementID *parent, SpriteSheet *sprite_sheet, float x, float y)
   : EntityBase(parent, "krampus", x, y)
   , state_is_busy(false)
   , state(STANDING)
   , sprite_sheet(sprite_sheet)
{
   place.size = vec2d(120, 30);
   bitmap.bitmap(sprite_sheet->get_sprite(18));
   bitmap.align(0.5, 1.0);
   bitmap.scale(2.0, 2.0);
}



void KrampusEntity::update()
{
   state_counter += 1.0 / 60.0;

   switch(state)
   {
   case STANDING:
      break;
   case ATTACKING:
      {
         float speed = 2.0;
         float playhead = state_counter * speed;
         if (playhead >= 1.0) set_state(STANDING, true);
         else if (playhead >= 0.7) bitmap.bitmap(sprite_sheet->get_sprite(22));
         else if (playhead >= 0.5) bitmap.bitmap(sprite_sheet->get_sprite(21));
         else if (playhead >= 0.4) bitmap.bitmap(sprite_sheet->get_sprite(20));
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



bool KrampusEntity::set_state(state_t new_state, bool override_if_busy)
{
   if (state_is_busy && !override_if_busy) return false;

   state_counter = 0.0;
   state = new_state;

   switch(new_state)
   {
   case STANDING:
      bitmap.bitmap(sprite_sheet->get_sprite(18));
      velocity.position = vec2d(0.0, 0.0);
      break;
   case ATTACKING:
      bitmap.bitmap(sprite_sheet->get_sprite(19));
      velocity.position = vec2d(0.0, 0.0);
   default:
      return false;
      break;
   }

   return true;
}






