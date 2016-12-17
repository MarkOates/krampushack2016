


#include <allegro_flare/framework.h>
#include <screens/title_screen.h>



TitleScreen::TitleScreen(Display *display)
   : Screen(display)
   , fonts()
   , menu_cursor_pos(0)
   , title(TextObject("KrampusHack"))
   , menu_items({TextObject("start"), TextObject("exit")})
{
   ALLEGRO_FONT *font = fonts["ChronoTrigger.ttf 20"];

   title.font(font)
      .align(0.5, 0.5)
      .scale(5, 5);

   for (auto &menu_item : menu_items)
   {
      menu_item.font(font)
         .align(0.5, 0.5)
         .scale(1.0, 1.0);
   }
}



void TitleScreen::primary_timer_func()
{
   // draw the title
   title.draw();

   // draw the menu options
   for (auto &menu_item : menu_items) menu_item.draw();
}



void TitleScreen::key_down_func()
{
   switch(Framework::current_event->keyboard.keycode)
   {
   case ALLEGRO_KEY_UP:
      cursor_up_action();
      break;
   case ALLEGRO_KEY_DOWN:
      cursor_down_action();
      break;
   case ALLEGRO_KEY_ENTER:
   case ALLEGRO_KEY_SPACE:
      select_option_action();
      break;
   }
}



void TitleScreen::cursor_up_action()
{
   menu_cursor_pos--;
   if (menu_cursor_pos < 0) menu_cursor_pos = menu_items.size() - 1;
}



void TitleScreen::cursor_down_action()
{
   menu_cursor_pos++;
   if (menu_cursor_pos >= menu_items.size()) menu_cursor_pos = 0;
}



void TitleScreen::select_option_action()
{
   // todo
}



