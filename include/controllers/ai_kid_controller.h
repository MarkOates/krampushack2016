#pragma once



#include <entities/kid_entity.h>



class AIKidController
{
private:
   float state_counter;
   KidEntity *kid;
   KidEntity::state_t select_random_state();
   void set_new_state();

public:
   AIKidController(KidEntity *kid);

   void update();
};



