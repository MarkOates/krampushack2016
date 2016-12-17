


#include <allegro_flare/allegro_flare.h>

#include <screens/title_screen.h>
#include <screens/game_play_screen.h>
#include <user_events.h>



class KrampusHackProject : public Screen
{
public:
   Screen *current_screen;
	KrampusHackProject(Display *display)
      : Screen(display)
      , current_screen(new TitleScreen(display))
   {}

   void user_event_func() override
   {
      ALLEGRO_EVENT *event = Framework::current_event;

      switch (event->user.type)
      {
      case START_GAME_EVENT:
         delete current_screen;
         current_screen = new GamePlayScreen(display);
         break;
      }
   }
};



int main(int argc, char **argv)
{
	Framework::initialize();
	Display *display = Framework::create_display();
	KrampusHackProject *proj = new KrampusHackProject(display);
	Framework::run_loop();
	return 0;
}



