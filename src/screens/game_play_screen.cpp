


#include <screens/game_play_screen.h>

#include <allegro_flare/allegro_flare.h>



GamePlayScreen::GamePlayScreen(Display *display)
   : Screen(display)
{}



void GamePlayScreen::primary_timer_func()
{
   al_clear_to_color(color::green);
}



