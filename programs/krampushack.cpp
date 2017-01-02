


#include <allegro_flare/allegro_flare.h>

#include <controllers/audio_controller.h>
#include <emitters/user_event_emitter.h>
#include <screens/title_screen.h>
#include <screens/game_play_screen.h>
#include <user_events.h>



class KrampusHackProject : public Screen
{
public:
   Screen *current_screen;
   AudioController audio_controller;
	KrampusHackProject(Display *display)
      : Screen(display)
      , current_screen(nullptr)
      , audio_controller()
   {
      UserEventEmitter::emit_event(START_TITLE_SCREEN);
   }

   void user_event_func() override
   {
      ALLEGRO_EVENT *event = Framework::current_event;

      switch (event->user.type)
      {
      case START_TITLE_SCREEN:
         if (current_screen) delete current_screen;
         current_screen = new TitleScreen(display);
         audio_controller.play_game_show_music();
         break;
      case START_GAME_EVENT:
         delete current_screen;
         current_screen = new GamePlayScreen(display);
         break;
      case PLAY_MUSIC_TRACK:
         {
            int track_id = event->user.data1;
            audio_controller.play_audio_track_by_id(track_id);
         }
         break;
      case QUIT_GAME_EVENT:
         Framework::shutdown_program = true;
         break;
      }
   }
};



int main(int argc, char **argv)
{
	Framework::initialize();
	Display *display = Framework::create_display(1280, 720, ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);
   KrampusHackProject *proj = new KrampusHackProject(display);
	Framework::run_loop();
	return 0;
}



