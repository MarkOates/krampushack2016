#pragma once



#include <allegro_flare/screen.h>

#include <controllers/player_krampus_controller.h>
#include <helpers/game_play_screen_state_helper.h>
#include <models/camera.h>
#include <models/inventory.h>
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
   state_t state;
   Scene *scene;
   PlayerKrampusController player_krampus_controller;
   Inventory player_inventory;
   GamePlayScreenStateHelper state_helper;
   Camera camera;

   friend class GamePlayScreenStateHelper;

   int _item_recently_collected;

public:
   GamePlayScreen(Display *display);

   void primary_timer_func() override;
   void key_down_func() override;
   void key_up_func() override;
   void user_event_func() override;

   void update();
   void draw();

   void set_state(state_t new_state);
   void enter_scene(int scene_to_enter);
};



