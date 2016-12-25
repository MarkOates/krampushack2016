


#include <screens/game_play_screen.h>

#include <allegro_flare/allegro_flare.h>
#include <factories/scene_factory.h>
#include <models/hud.h>
#include <user_events.h>



#define TEST_SCENE_ID 1



GamePlayScreen::GamePlayScreen(Display *display)
   : Screen(display)
   , scene(nullptr)
   , state(NONE)
   , player_krampus_controller()
   , player_inventory()
   , state_helper(this)
   , camera(display, nullptr)
{
   enter_scene(TEST_SCENE_ID);
   set_state(GAME_PLAY);
}



void GamePlayScreen::primary_timer_func()
{
   update();
   draw();
}



void GamePlayScreen::key_down_func()
{
   int al_keycode = Framework::current_event->keyboard.keycode;

   player_krampus_controller.on_key_down(al_keycode);
}



void GamePlayScreen::key_up_func()
{
   int al_keycode = Framework::current_event->keyboard.keycode;

   player_krampus_controller.on_key_up(al_keycode);
}



void GamePlayScreen::user_event_func()
{
   ALLEGRO_EVENT *event = Framework::current_event;

   switch (event->user.type)
   {
   case ENTER_DOOR_EVENT:
      {
         int scene_id = event->user.data1;
         enter_scene(scene_id);
         break;
      }
   case COLLECT_ITEM_EVENT:
      {
         int item_type_int = event->user.data1;
         player_inventory.add_item(item_type_int);
         set_state(ITEM_COLLECTED);
         break;
      }
   }
}



void GamePlayScreen::update()
{
   state_helper.update_state();
}



void GamePlayScreen::draw()
{
   state_helper.draw_state();

   HUD hud(3, 10, &player_inventory, 3, 6);
   hud.draw();
}



void GamePlayScreen::set_state(state_t new_state)
{
   state_helper.set_state(new_state);
}



void GamePlayScreen::enter_scene(int scene_id)
{
   if (scene) delete scene;

   scene = SceneFactory::create_scene_by_id(scene_id);

   KrampusEntity *krampus = static_cast<KrampusEntity *>(scene->find_first("type", "krampus"));

   player_krampus_controller.set_krampus(krampus);

   camera.set_target(krampus);
}



