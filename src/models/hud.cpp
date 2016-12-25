


#include <models/hud.h>

#include <allegro_flare/framework.h>
#include <sstream>



HUD::HUD(int player_health, int player_max_health, Inventory *player_inventory, int num_good_children, int num_naughty_children)
   : player_health(player_health)
   , player_max_health(player_max_health)
   , player_inventory(player_inventory)
   , num_good_children(num_good_children)
   , num_naughty_children(num_naughty_children)
{
}



void HUD::draw()
{
   ALLEGRO_FONT *font = Framework::font("ChronoTrigger.ttf 40");

   std::stringstream hud_str;

   hud_str << "Player: " << player_health << "/" << player_max_health;
   hud_str << "     Inventory: " << player_inventory->get_str();
   hud_str << "     Good Children: " << num_good_children;
   hud_str << "     Naughty Children: " << num_naughty_children;

   al_draw_text(font, color::white, 10, 10, 0, hud_str.str().c_str());
}



