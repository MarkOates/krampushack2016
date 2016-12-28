


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
{
   ALLEGRO_BITMAP *bmp = create_pixel_perfect_scaled_render(Framework::bitmap("top_hud-01.png"), 5);
   chrome_bitmap.bitmap(bmp);
   chrome_bitmap.align(0.5, 0.0);
   chrome_bitmap.scale(0.95);
   chrome_bitmap.position(1280/2, 20);
}



void HUD::set_values(int player_health, int player_max_health)
{
   this->player_health = player_health;
   this->player_max_health = player_max_health;
}



void HUD::draw()
{
   chrome_bitmap.draw();

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
}



