#pragma once



#include <framework/screen.h>

#include <controllers/player_krampus_controller.h>
#include <controllers/ai_kid_controller.h>
#include <helpers/game_play_screen_state_helper.h>
#include <models/camera.h>
#include <models/hud.h>
#include <models/inventory.h>
#include <models/naughty_list.h>
#include <models/scene.h>



class GamePlayScreen : public Screen
{
private:
   enum state_t
   {
      NONE,
      GET_READY,
      GAME_PLAY,
      GAME_LOST,
      GAME_WON,
      PAUSED,
      ITEM_COLLECTED,
      USING_STONE_OF_DEFIANCE,
      ENTERING_THROUGH_DOOR,
      BOSS_FIGHT_WARM_UP,
      BOSS_FIGHT,
      STATE_COMPLETE
   };
   state_t state;
   Scene *scene;
   PlayerKrampusController player_krampus_controller;
   std::vector<AIKidController> ai_kid_controllers;
   Inventory player_inventory;
   NaughtyList naughty_list;
   HUD hud;
   GamePlayScreenStateHelper state_helper;
   Camera camera;

   friend class GamePlayScreenStateHelper;

   int _item_recently_collected;
   void _destroy_ai_kid_controller_for(KidEntity *kid);

public:
   GamePlayScreen(Display *display);

   void primary_timer_func() override;
   void key_down_func() override;
   void key_up_func() override;
   void user_event_func() override;

   void update();
   void draw();

   void set_state(state_t new_state);
   void enter_scene(int scene_to_enter, char door_name='!');
};



