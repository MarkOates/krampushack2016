#pragma once



#include <entities/kid_entity.h>



class AIKidController
{
private:
   float state_counter;
   KidEntity *kid;
   KidEntity::state_t _get_a_random_state();
   KidEntity::state_t _get_a_random_state_different_from_current_one();
   void set_new_state();

public:
   AIKidController(KidEntity *kid);

   void update();
   bool is_controlling(KidEntity *possibly_controlled_kid);
};



