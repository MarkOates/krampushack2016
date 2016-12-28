


#include <models/hud.h>

#include <allegro_flare/framework.h>
#include <sstream>



HUD::HUD(Inventory *player_inventory, NaughtyList *naughty_list)
   : player_health(0)
   , player_max_health(0)
   , player_inventory(player_inventory)
   , naughty_list(naughty_list)
   , num_alive_naughty_children(0)
   , num_alive_nice_children(0)
   , num_alive_adults(0)
   , num_total_naughty_children(0)
   , num_total_nice_children(0)
   , num_total_adults(0)
{
}



void HUD::set_values(
      int player_health,
      int player_max_health,
      int num_alive_naughty_children,
      int num_alive_nice_children,
      int num_alive_adults,
      int num_total_naughty_children,
      int num_total_nice_children,
      int num_total_adults
      )
{
   this->player_health = player_health;
   this->player_max_health = player_max_health;
   this->num_alive_naughty_children = num_alive_naughty_children;
   this->num_alive_nice_children = num_alive_nice_children;
   this->num_alive_adults = num_alive_adults;
   this->num_total_naughty_children = num_total_naughty_children;
   this->num_total_nice_children = num_total_nice_children;
   this->num_total_adults = num_total_adults;
}



void HUD::draw()
{
   ALLEGRO_FONT *font = Framework::font("ChronoTrigger.ttf 40");

   std::stringstream hud_str;

   hud_str << "Player: " << player_health << "/" << player_max_health;
   hud_str << "     Inventory: " << player_inventory->get_str();
   hud_str << "     Naughty Kids: " << num_alive_naughty_children << "/" << num_total_naughty_children;
   hud_str << "     Nice Kids: " << num_alive_nice_children << "/" << num_total_nice_children;
   hud_str << "     Adults: " << num_alive_adults;

   al_draw_text(font, color::white, 10, 10, 0, hud_str.str().c_str());
}



