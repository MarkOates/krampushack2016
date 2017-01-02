#pragma once



#include <allegro5/allegro_font.h>
#include <allegro_flare/screen.h>



class StoryboardScreen : public Screen
{
private:
   ALLEGRO_FONT *text_font;

public:
	StoryboardScreen(Display *display);

   void primary_timer_func() override;
   void key_down_func() override;
};



