


#include <helpers/game_play_screen_state_helper.h>

#include <factories/dialogue_factory.h>
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
}



void GamePlayScreenStateHelper::update_state()
{
   state_counter += 1.0 / 60.0;

   switch (game_play_screen->state)
   {
   case GamePlayScreen::GAME_PLAY:
      game_play_screen->player_krampus_controller.update_polled_keyboard_input();
      if (game_play_screen->scene) game_play_screen->scene->update_all();
      break;
   case GamePlayScreen::ITEM_COLLECTED:
      if (state_counter > 3.0) set_state(GamePlayScreen::GAME_PLAY);
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
         ItemDialogue dialogue = DialogueFactory::build_collected_item_dialog(ITEM_TYPE_CLUB);
         dialogue.draw(0);
         break;
      }
   default:
      break;
   }
}



void GamePlayScreenStateHelper::draw_scene_with_camera()
{
   game_play_screen->camera.start_transform();
   game_play_screen->scene->draw_all();
   game_play_screen->camera.restore_transform();
}



