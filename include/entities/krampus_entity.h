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
   SpriteSheet *sprite_sheet;

public:
   KrampusEntity(ElementID *parent, SpriteSheet *sprite_sheet, float x, float y);

   void update() override;

   void attack();

   bool set_state(state_t new_state, bool override_if_busy=false);
};



