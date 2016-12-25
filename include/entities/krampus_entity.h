#pragma once



#include <entities/entity_base.h>
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
      CELEBRATING,
      ATTACKING,
      DEAD
   };
   int state;
   float state_counter;
   bool state_is_busy;
   int walking_speed;
   bool facing_right;
   SpriteSheet *sprite_sheet;

   bool set_state(state_t new_state, bool override_if_busy=false);

public:
   KrampusEntity(ElementID *parent, SpriteSheet *sprite_sheet, float x, float y);
   virtual ~KrampusEntity();

   void update() override;

   void attack();
   void stand_still();
   void celebrate();
   void walk_up();
   void walk_down();
   void walk_left();
   void walk_right();
   void face_left();
   void face_right();

   bool is_idle();
};



