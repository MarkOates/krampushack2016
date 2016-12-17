


#include <allegro_flare/allegro_flare.h>



class KrampusHackProject : public Screen
{
public:
	KrampusHackProject(Display *display)
      : Screen(display)
   {}
};



int main(int argc, char **argv)
{
	Framework::initialize();
	Display *display = Framework::create_display();
	KrampusHackProject *proj = new KrampusHackProject(display);
	Framework::run_loop();
	return 0;
}



