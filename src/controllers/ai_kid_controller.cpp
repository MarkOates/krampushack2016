


#include <controllers/ai_kid_controller.h>



AIKidController::AIKidController(KidEntity *kid)
   : kid(kid)
   , state_counter(0.0)
{}



KidEntity::state_t AIKidController::select_random_state()
{
   std::vector<KidEntity::state_t> possible_states = {
         KidEntity::STATE_STANDING_STILL,
         KidEntity::STATE_WALKING_UP,
         KidEntity::STATE_WALKING_DOWN,
         KidEntity::STATE_WALKING_LEFT,
         KidEntity::STATE_WALKING_RIGHT
      };

   return possible_states[random_int(0, possible_states.size()-1)];
}



void AIKidController::set_new_state()
{
   float duration_until_next_state_chage = random_float(0.5, 5.0);

   KidEntity::state_t next_state = select_random_state();
   while ((next_state = select_random_state()) != kid->state);

   kid->set_state(next_state);

   state_counter = duration_until_next_state_chage;
}



void AIKidController::update()
{
   state_counter -= 1.0/60.0;

   if (state_counter <= 0) set_new_state();
}



