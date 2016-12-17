


#include <screens/game_play_screen.h>

#include <allegro_flare/allegro_flare.h>
#include <factories/scene_factory.h>



GamePlayScreen::GamePlayScreen(Display *display)
   : Screen(display)
   , scene(nullptr)
{
   scene = SceneFactory::create_test_scene();
}



void GamePlayScreen::primary_timer_func()
{
   al_clear_to_color(color::hex("2f3938"));

   if (scene) scene->update_all();
   if (scene) scene->draw_all();
}



