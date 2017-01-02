


#include <screens/storyboard_screen.h>

#include <emitters/user_event_emitter.h>
#include <allegro_flare/framework.h>
#include <user_events.h>



StoryboardScreen::StoryboardScreen(Display *display)
   : Screen(display)
   , text_font(Framework::font("ChronoTrigger.ttf 60"))
{}



void StoryboardScreen::primary_timer_func()
{
   al_clear_to_color(color::hex("11141a"));

   std::string text = "Uh oh!  There has been a big Christmas mix up this year and Krampus accidentally got a bad list of Naughty kids.  But it's Christmas Eve and he has to punish all the naughty kids or it'll be a Christmas disaster!";

   float x_padding = 150;
   float y_padding = 150;

   al_draw_multiline_text(
         text_font,
         color::hex("d0f2c5"),
         x_padding,
         y_padding,
         display->width() - x_padding*2,
         al_get_font_line_height(text_font)*1.75,
         0,
         text.c_str()
      );
}



void StoryboardScreen::key_down_func()
{
   UserEventEmitter::emit_event(START_GAME_EVENT);
}



