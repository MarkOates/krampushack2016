


#include <screens/game_play_screen.h>

#include <allegro_flare/allegro_flare.h>
#include <factories/scene_factory.h>



GamePlayScreen::GamePlayScreen(Display *display)
   : Screen(display)
   , scene(nullptr)
   , state(NONE)
   , player_krampus_controller()
{
   scene = SceneFactory::create_test_scene();

   player_krampus_controller.set_krampus(
         static_cast<KrampusEntity *>(scene->find_first("type", "krampus"))
      );

   set_state(GET_READY);
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



void GamePlayScreen::update()
{
   if (scene) scene->update_all();
}



void GamePlayScreen::draw()
{
   al_clear_to_color(color::hex("1f4630"));
   if (scene) scene->draw_all();
}



void GamePlayScreen::set_state(state_t new_state)
{
   state = new_state;
}



