#pragma once



#include <allegro_flare/screen.h>



class GamePlayScreen : public Screen
{
public:
   GamePlayScreen(Display *display);

   void primary_timer_func() override;
};



