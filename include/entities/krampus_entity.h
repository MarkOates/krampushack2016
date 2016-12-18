#pragma once



#include <models/entity_base.h>
#include <sprite_sheet.h>



class KrampusEntity : public EntityBase
{
public:
   enum state_t
   {
      WALKING_UP,
      WALKING_DOWN,
      WALKING_RIGHT,
      WALKING_LEFT,
      STANDING,
      ATTACKING,
      DEAD
   };
   int state;
   float state_counter;
   bool state_is_busy;
   bool facing_right;
   SpriteSheet *sprite_sheet;

   bool set_state(state_t new_state, bool override_if_busy=false);

public:
   KrampusEntity(ElementID *parent, SpriteSheet *sprite_sheet, float x, float y);

   void update() override;

   void attack();
   void stand_still();
   void walk_left();
   void walk_right();
   void face_left();
   void face_right();
};



