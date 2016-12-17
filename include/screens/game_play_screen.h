#pragma once



#include <allegro_flare/screen.h>

#include <models/scene.h>



class GamePlayScreen : public Screen
{
public:
   GamePlayScreen(Display *display);
   Scene *scene;

   void primary_timer_func() override;

   void update();
   void draw();
};



