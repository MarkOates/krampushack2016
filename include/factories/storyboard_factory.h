#pragma once



#include <screens/storyboard_screen.h>



class StoryboardFactory
{
public:
   static StoryboardScreen *create_opening_storyboard_screen(Display *display);
   static StoryboardScreen *create_closing_storyboard_screen(Display *display);
};



