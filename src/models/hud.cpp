


#include <models/hud.h>

#include <allegro_flare/framework.h>
#include <allegro_flare/image_processing.h>
#include <sstream>



HUD::HUD(Inventory *player_inventory, NaughtyList *naughty_list)
   : player_inventory(player_inventory)
   , naughty_list(naughty_list)
   , player_health(0)
   , player_max_health(0)
   , chrome_bitmap(nullptr)
   , font(Framework::font("ChronoTrigger.ttf 40"))
   , black_bar_counter(0)
   , sprite_sheet("sprites_grid-05-black_outline.png", 32, 32, 6, 6, 4)
   , club_item_bitmap(nullptr)
   , key_item_bitmap(nullptr)
   , stone_of_defiance_item_bitmap(nullptr)
   , naughty_list_item_bitmap(nullptr)
{
   ALLEGRO_BITMAP *bmp = create_pixel_perfect_scaled_render(Framework::bitmap("top_hud-02.png"), 5);
   chrome_bitmap.bitmap(bmp);

   chrome_bitmap.position(1280/2, 20);
   chrome_bitmap.align(0.5, 2.0);
   chrome_bitmap.scale(0.95);

   club_item_bitmap.bitmap(sprite_sheet.get_sprite(23))
      .position(640, 84-40)
      .rotation(0.4)
      .scale(2.0, 2.0)
      .align(0.5, 0.5);

   stone_of_defiance_item_bitmap.bitmap(sprite_sheet.get_sprite(24))
      .position(435*2, 48*2-20)
      .rotation(0.1)
      .align(0.5, 0.5);

   naughty_list_item_bitmap.bitmap(sprite_sheet.get_sprite(25))
      .position(503*2, 48*2-20)
      .flags(ALLEGRO_FLIP_HORIZONTAL)
      .rotation(0.1)
      .align(0.5, 0.5);

   key_item_bitmap.bitmap(sprite_sheet.get_sprite(26))
      .position(568*2, 48*2-40)
      .rotation(0.1)
      .align(0.5, 0.5);

   set_to_game_play_mode();
}



void HUD::set_mode(mode_t new_mode)
{
   mode = new_mode;

   switch(new_mode)
   {
   case MODE_GAME_PLAY:
      chrome_bitmap.get_attr("align_y") = 0.0; //<- a really annoying way to have to do this
      black_bar_counter = 0.0;
      break;
   case MODE_CINEMA:
      chrome_bitmap.get_attr("align_y") = 2.0; //<- a really annoying way to have to do this
      black_bar_counter = 1.0;
      break;
   };
}



void HUD::set_values(int player_health, int player_max_health)
{
   this->player_health = player_health;
   this->player_max_health = player_max_health;
}



void HUD::draw()
{
   chrome_bitmap.draw();

   club_item_bitmap.draw();
   key_item_bitmap.draw();
   stone_of_defiance_item_bitmap.draw();
   naughty_list_item_bitmap.draw();


   std::stringstream hud_str;

   hud_str << "Player: " << player_health << "/" << player_max_health;
   hud_str << "     Inventory: " << player_inventory->get_str();
   hud_str << "     Naughty Kids: "
      << naughty_list->get_num_alive_naughty_kids()
      << "/" << naughty_list->get_num_total_naughty_kids();
   hud_str << "     Nice Kids: "
      << naughty_list->get_num_alive_nice_kids()
      << "/" << naughty_list->get_num_total_nice_kids();
   hud_str << "     Adults: " << naughty_list->get_num_alive_adults();

   al_draw_text(font, color::white, 10, 720-50, 0, hud_str.str().c_str());

   // draw the black bars
   float black_bar_height = 100;
   float top_bar_y = 0 - black_bar_height * (1.0 - black_bar_counter);
   float bottom_bar_y = 720-black_bar_height + black_bar_height * (1.0 - black_bar_counter);
   al_draw_filled_rectangle(0, top_bar_y, 1280, top_bar_y+black_bar_height, color::black);
   al_draw_filled_rectangle(0, bottom_bar_y, 1280, bottom_bar_y+black_bar_height, color::black);
}



void HUD::set_to_cinema_mode()
{
   set_mode(MODE_CINEMA);
}



void HUD::set_to_game_play_mode()
{
   set_mode(MODE_GAME_PLAY);
}



