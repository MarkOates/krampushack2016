


#include <helpers/game_play_screen_state_helper.h>

#include <factories/dialogue_factory.h>
#include <helpers/scene_collection_helper.h>
#include <screens/game_play_screen.h>
#include <item_type_nums.h>



GamePlayScreenStateHelper::GamePlayScreenStateHelper(GamePlayScreen *game_play_screen)
   : game_play_screen(game_play_screen)
   , state_counter(1.0)
{}



void GamePlayScreenStateHelper::set_state(int new_state)
{
   game_play_screen->state = (GamePlayScreen::state_t)new_state;
   state_counter = 0.0;

   switch (game_play_screen->state)
   {
   case GamePlayScreen::GAME_PLAY:
      break;
   case GamePlayScreen::ITEM_COLLECTED:
      {
         SceneCollectionHelper collections(game_play_screen->scene);
         KrampusEntity *krampus = collections.get_krampus();
         if (krampus) krampus->celebrate();
         game_play_screen->camera.zoom_to(0.6, 0.3);
      }
      break;
   case GamePlayScreen::ENTERING_THROUGH_DOOR:
      game_play_screen->camera.set_overlay_color(color::black);
      game_play_screen->camera.fade_to_clear(1.5);
      game_play_screen->camera.set_zoom(0.8);
      game_play_screen->camera.zoom_to(1.0, 2.2);
      break;
   default:
      break;
   }
}



void GamePlayScreenStateHelper::update_state()
{
   state_counter += 1.0 / 60.0;

   switch (game_play_screen->state)
   {
   case GamePlayScreen::GAME_PLAY:
      game_play_screen->player_krampus_controller.update_polled_keyboard_input();
      update_scene();
      break;
   case GamePlayScreen::ITEM_COLLECTED:
      {
         SceneCollectionHelper collections(game_play_screen->scene);
         KrampusEntity *krampus = collections.get_krampus();
         if (krampus) krampus->update();
         if (state_counter > 3.0)
         {
            if (krampus) krampus->stand_still();
            game_play_screen->camera.zoom_to(1.0, 0.6);
            set_state(GamePlayScreen::GAME_PLAY);
         }
      }
      break;
   case GamePlayScreen::ENTERING_THROUGH_DOOR:
      update_scene();
      if (state_counter > 0.65)
      {
         SceneCollectionHelper collections(game_play_screen->scene);
         KrampusEntity *krampus = collections.get_krampus();
         if (krampus) krampus->stand_still();
         set_state(GamePlayScreen::GAME_PLAY);
      }
      break;
   default:
      break;
   }

   // always update the camera, regardless of state
   game_play_screen->camera.update(game_play_screen->scene->get_width());
}



void GamePlayScreenStateHelper::draw_state()
{
   al_clear_to_color(color::hex("1f4630"));

   switch (game_play_screen->state)
   {
   case GamePlayScreen::GAME_PLAY:
      {
         if (game_play_screen->scene) draw_scene_with_camera();
         break;
      }
   case GamePlayScreen::ITEM_COLLECTED:
      {
         if (game_play_screen->scene) draw_scene_with_camera();
         ItemDialogue dialogue = DialogueFactory::build_collected_item_dialog(game_play_screen->_item_recently_collected);
         dialogue.draw(0);
         break;
      }
   case GamePlayScreen::ENTERING_THROUGH_DOOR:
      {
         if (game_play_screen->scene) draw_scene_with_camera();
      }
   default:
      break;
   }

   // draw the camera's overlay color
   game_play_screen->camera.draw_overlay();
}



void GamePlayScreenStateHelper::update_scene()
{
   if (!game_play_screen->scene) return;

   for (auto &ai_kid_controller : game_play_screen->ai_kid_controllers)
      ai_kid_controller.update();

   game_play_screen->scene->update_all();

   // destroy the AI controllers for kids flagged for deletion
   SceneCollectionHelper collections(game_play_screen->scene);
   for (auto &kid : collections.get_kids_flagged_for_deletion())
      game_play_screen->_destroy_ai_kid_controller_for(kid);

   // now remove those entities
   game_play_screen->scene->cleanup_all();
}



void GamePlayScreenStateHelper::draw_scene_with_camera()
{
   game_play_screen->camera.start_transform();
   game_play_screen->scene->draw_all();
   game_play_screen->camera.restore_transform();
}



