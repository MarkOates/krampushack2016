


#include <screens/game_play_screen.h>

#include <allegro_flare/allegro_flare.h>
#include <entities/door_entity.h>
#include <factories/entity_factory.h>
#include <factories/scene_factory.h>
#include <helpers/scene_collection_helper.h>
#include <models/hud.h>
#include <user_events.h>



#define TEST_SCENE_ID 999
#define START_SCENE_ID 0



GamePlayScreen::GamePlayScreen(Display *display)
   : Screen(display)
   , scene(nullptr)
   , state(NONE)
   , player_krampus_controller()
   , ai_kid_controllers()
   , player_inventory()
   , naughty_list()
   , state_helper(this)
   , camera(display, nullptr)
   , _item_recently_collected(0)
{
   enter_scene(START_SCENE_ID);
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

   switch (state)
   {
   case GAME_PLAY:
      player_krampus_controller.on_key_down(al_keycode);
      break;
   case ENTERING_THROUGH_DOOR:
      // nothing
      break;
   default:
      break;
   }
}



void GamePlayScreen::key_up_func()
{
   int al_keycode = Framework::current_event->keyboard.keycode;

   switch (state)
   {
   case GAME_PLAY:
      player_krampus_controller.on_key_up(al_keycode);
      break;
   case ENTERING_THROUGH_DOOR:
      // nothing
      break;
   default:
      break;
   }
}



void GamePlayScreen::user_event_func()
{
   ALLEGRO_EVENT *event = Framework::current_event;

   switch (event->user.type)
   {
   case ENTER_DOOR_EVENT:
      {
         int scene_id = event->user.data1;
         std::string destination_door_name;
         destination_door_name.push_back((char)event->user.data2);
         enter_scene(scene_id, destination_door_name[0]);
         break;
      }
   case COLLECT_ITEM_EVENT:
      {
         int item_type_int = event->user.data1;
         player_inventory.add_item(item_type_int);
         _item_recently_collected = item_type_int;
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

   int num_nice_kids = naughty_list.get_num_alive_nice_kids();
   int num_naughty_kids = naughty_list.get_num_alive_naughty_kids();
   int num_adults = naughty_list.get_num_alive_adults();
   int total_nice_kids = naughty_list.get_num_total_nice_kids();
   int total_naughty_kids = naughty_list.get_num_total_naughty_kids();
   int total_adults = naughty_list.get_num_total_adults();

   HUD hud(&player_inventory);
   hud.set_values(3, 10, num_naughty_kids, num_nice_kids, num_adults, total_naughty_kids, total_nice_kids, total_adults);
   hud.draw();
}



void GamePlayScreen::set_state(state_t new_state)
{
   state_helper.set_state(new_state);
}



void GamePlayScreen::enter_scene(int scene_id, char door_name)
{
   if (scene) delete scene;

   scene = SceneFactory::create_scene_by_id(scene_id);

   SceneCollectionHelper collections(scene);

   std::vector<NaughtyList::Kid> naughty_list_kids = naughty_list.get_alive_kids_for_scene(scene_id);
   KrampusEntity *krampus = collections.get_krampus();
   DoorEntity *door = collections.get_door(door_name);

   // create entities for the alive kids in this scene
   for (auto &kid : naughty_list_kids)
   {
      float min_y, max_y;
      float scene_width = scene->get_width();
      scene->get_y_bounds(&min_y, &max_y);

      float new_kid_x = random_float(0, scene->get_width());
      float new_kid_y = random_float(min_y, max_y);

      EntityFactory::create_random_kid(scene, new_kid_x, new_kid_y);
   }

   // create AI controllers to control the kids
   ai_kid_controllers.clear();

   for (auto &kid : collections.get_kids())
      ai_kid_controllers.push_back(AIKidController(kid));

   // set the player controller to control krampus
   player_krampus_controller.set_krampus(krampus);

   // have the camera follow krampus
   camera.set_target(krampus);

   // place krampus at the destination_door and walk down
   if (door)
   {
      krampus->place.position = door->place.position + vec2d(0.0, door->place.h/2 + krampus->place.h/2) + 5;
      krampus->walk_down();
   }

   set_state(ENTERING_THROUGH_DOOR);
}



void GamePlayScreen::_destroy_ai_kid_controller_for(KidEntity *kid)
{
   for (unsigned i=0; i<ai_kid_controllers.size(); i++)
      if (ai_kid_controllers[i].is_controlling(kid))
      {
         ai_kid_controllers.erase(ai_kid_controllers.begin() + i);
         i--;
      }
}



