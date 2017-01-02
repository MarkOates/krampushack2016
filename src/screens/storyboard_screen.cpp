


#include <screens/storyboard_screen.h>

#include <emitters/user_event_emitter.h>
#include <allegro_flare/framework.h>
#include <user_events.h>



StoryboardScreen::StoryboardScreen(Display *display)
   : Screen(display)
   , text_font(Framework::font("ChronoTrigger.ttf 60"))
   , pages()
   , current_page(0)
{
   pages.push_back("Oh no!\n\nThere has been a big Christmas mix up this year and Krampus accidentally got the wrong list of Naughty kids.");
   pages.push_back("What's even worse is that it's already Christmas Eve!\n\nKrampus needs to punish all the naughty kids or it'll be a Christmas disaster!");
   pages.push_back("Your task:\n\nTravel around Krampus cavern, find out who the naughty kids are, and deliver their well deserved Christmas punishment.");
   pages.push_back("Use the ARROW KEYS and SPACEBAR to play.  Once you get the legendary Stone of Defiance, you can activate it by pressing the R key.");
   pages.push_back("And one last thing!");
   pages.push_back("Good Luck!");
}



void StoryboardScreen::primary_timer_func()
{
   al_clear_to_color(color::hex("11141a"));

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
         pages[current_page].c_str()
      );
}



void StoryboardScreen::key_down_func()
{
   current_page++;

   if (current_page >= pages.size())
      UserEventEmitter::emit_event(START_GAME_EVENT);
}



