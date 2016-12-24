


#include <helpers/game_play_screen_state_helper.h>

#include <screens/game_play_screen.h>



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
   default:
      break;
   }
}



void GamePlayScreenStateHelper::draw_state()
{
   al_clear_to_color(color::hex("1f4630"));

   switch (game_play_screen->state)
   {
   case GamePlayScreen::GAME_PLAY:
      if (game_play_screen->scene) game_play_screen->scene->draw_all();
      break;
   default:
      break;
   }
}



