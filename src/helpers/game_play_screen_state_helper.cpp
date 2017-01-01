


#include <helpers/game_play_screen_state_helper.h>

#include <emitters/user_event_emitter.h>
#include <factories/dialogue_factory.h>
#include <helpers/scene_collection_helper.h>
#include <screens/game_play_screen.h>
#include <user_events.h>
#include <item_type_nums.h>



GamePlayScreenStateHelper::GamePlayScreenStateHelper(GamePlayScreen *game_play_screen)
   : game_play_screen(game_play_screen)
   , state_counter(1.0)
{}




void GamePlayScreenStateHelper::process_key_down(int al_keycode)
{
   switch (game_play_screen->state)
   {
   case GamePlayScreen::GAME_PLAY:
      game_play_screen->player_krampus_controller.on_key_down(al_keycode);
      break;
   case GamePlayScreen::ENTERING_THROUGH_DOOR:
      // nothing
      break;
   case GamePlayScreen::ITEM_COLLECTED:
       // can only close dialogue after a delay
      if (state_counter > 3.0
         && (al_keycode == ALLEGRO_KEY_SPACE || al_keycode == ALLEGRO_KEY_ENTER))
      {
         SceneCollectionHelper collections(game_play_screen->scene);
         KrampusEntity *krampus = collections.get_krampus();
         if (krampus) krampus->stand_still();
         game_play_screen->camera.zoom_to(1.0, 0.6);
         game_play_screen->camera.tilt_to(0.0, 0.3);
         set_state(GamePlayScreen::GAME_PLAY);
      }
      break;
   case GamePlayScreen::GAME_LOST:
       // can only close dialogue after a delay
      if (state_counter > 2.0
         && (al_keycode == ALLEGRO_KEY_SPACE || al_keycode == ALLEGRO_KEY_ENTER))
      {
         UserEventEmitter::emit_event(QUIT_GAME_EVENT);
      }
   default:
      break;
   }
}



void GamePlayScreenStateHelper::set_state(int new_state)
{
   game_play_screen->state = (GamePlayScreen::state_t)new_state;
   state_counter = 0.0;

   switch (game_play_screen->state)
   {
   case GamePlayScreen::GAME_PLAY:
      game_play_screen->hud.set_to_game_play_mode();
      break;
   case GamePlayScreen::ITEM_COLLECTED:
      {
         SceneCollectionHelper collections(game_play_screen->scene);
         KrampusEntity *krampus = collections.get_krampus();
         if (krampus) krampus->celebrate();
         game_play_screen->hud.set_to_cinema_mode();
         game_play_screen->camera.zoom_to(0.6, 0.3);
         game_play_screen->camera.tilt_to(random_bool() ? 0.1 : -0.1, 0.3);
      }
      break;
   case GamePlayScreen::ENTERING_THROUGH_DOOR:
      game_play_screen->camera.set_overlay_color(color::black);
      game_play_screen->hud.set_to_cinema_mode();
      game_play_screen->camera.fade_to_clear(1.5);
      game_play_screen->camera.set_zoom(0.8);
      game_play_screen->camera.zoom_to(1.0, 2.2);
      break;
   case GamePlayScreen::USING_STONE_OF_DEFIANCE:
      {
         game_play_screen->camera.zoom_to(1.15, 0.3);
         game_play_screen->camera.set_overlay_color(color::color(color::mix(color::red, color::violet, 0.5), 0.2));
         SceneCollectionHelper collections(game_play_screen->scene);
         for (auto &kid : collections.get_kids()) kid->reveal_behavior();
      }
      break;
   case GamePlayScreen::GAME_LOST:
      game_play_screen->camera.set_overlay_color(color::color(color::red, 0.3));
      game_play_screen->camera.zoom_to(0.8, 2.2);
      game_play_screen->camera.tilt_to(random_bool() ? 0.03 : -0.03, 0.3);
      break;
   default:
      break;
   }
}



void GamePlayScreenStateHelper::update_state()
{
   float previous_state_counter = state_counter;
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
      }
      break;
   case GamePlayScreen::ENTERING_THROUGH_DOOR:
      {
         SceneCollectionHelper collections(game_play_screen->scene);
         KrampusEntity *krampus = collections.get_krampus();
         if (previous_state_counter < 0.3 && state_counter >= 0.3)
         {
            krampus->walk_down();
         }
         if (previous_state_counter < 0.7 && state_counter >= 0.7)
         {
            if (krampus) krampus->stand_still();
         }
         if (previous_state_counter < 0.9 && state_counter >= 0.9)
         {
            set_state(GamePlayScreen::GAME_PLAY);
         }
         update_scene();
      }
      break;
   case GamePlayScreen::USING_STONE_OF_DEFIANCE:
      update_scene();
      if (previous_state_counter < 2.0 && state_counter >= 2.0)
      {
         game_play_screen->camera.zoom_to(1.0, 3.0);
         game_play_screen->camera.fade_to_clear(1.5);
         set_state(GamePlayScreen::GAME_PLAY);
      }
      break;
   case GamePlayScreen::GAME_LOST:
      update_scene();
      break;
   default:
      break;
   }

   // always update the camera, regardless of state
   game_play_screen->camera.update(game_play_screen->scene->get_width());

   // always update the hud, regardless of state
   game_play_screen->hud.set_values(3, 10);
}



void GamePlayScreenStateHelper::draw_state()
{
   al_clear_to_color(color::black);

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
         break;
      }
   case GamePlayScreen::USING_STONE_OF_DEFIANCE:
      {
         if (game_play_screen->scene) draw_scene_with_camera();
         break;
      }
   case GamePlayScreen::GAME_LOST:
      {
         if (game_play_screen->scene) draw_scene_with_camera();
         ItemDialogue dialogue = DialogueFactory::build_dialogue("Game Over\n\nOh no!  Don't hurt the nice children!  Only the naughty ones deserve that!");
         dialogue.draw(0);
         break;
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
   {
      // "kill" the kid off from the naughty list
      game_play_screen->naughty_list.kill_kid_by_name(kid->get_name());

      // destroy the ai controller
      game_play_screen->_destroy_ai_kid_controller_for(kid);
   }

   // now remove those entities
   game_play_screen->scene->cleanup_all();
}



void GamePlayScreenStateHelper::draw_scene_with_camera()
{
   game_play_screen->camera.start_transform();
   game_play_screen->scene->draw_all();
   game_play_screen->camera.restore_transform();

   game_play_screen->hud.draw();
}



