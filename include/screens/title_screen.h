#pragma once



#include <allegro_flare/screen.h>
#include <allegro_flare/objects/text_object.h>



class TitleScreen : public Screen
{
public:
   FontBin fonts;
   int menu_cursor_pos;
   TextObject title;
   std::vector<TextObject> menu_items;

	TitleScreen(Display *display);

   void primary_timer_func() override;
   void key_down_func() override;

   void cursor_up_action();
   void cursor_down_action();
   void select_option_action();

   void refresh_focused_menu_item();
};



