#pragma once



#include <allegro_flare/screen.h>

#include <models/scene.h>



class GamePlayScreen : public Screen
{
private:
   enum state_t
   {
      NONE,
      GET_READY,
      GAME_PLAY,
      PAUSED,
      ITEM_COLLECTED,
      TRAVEL_BETWEEN_DOORS,
      BOSS_FIGHT_WARM_UP,
      BOSS_FIGHT,
      STATE_COMPLETE
   };

public:
   GamePlayScreen(Display *display);
   Scene *scene;
   state_t state;

   void primary_timer_func() override;

   void update();
   void draw();

   void set_state(state_t new_state);
};



