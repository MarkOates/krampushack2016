#pragma once



#include <models/inventory.h>



class HUD
{
private:
   Inventory *player_inventory;
   int player_health;
   int player_max_health;
   int num_alive_nice_children;
   int num_alive_naughty_children;
   int num_alive_adults;
   int num_total_nice_children;
   int num_total_naughty_children;
   int num_total_adults;

public:
   HUD(Inventory *player_inventory);

   void set_values(
      int player_health,
      int player_max_health,
      int num_alive_naughty_children,
      int num_alive_nice_children,
      int num_alive_adults,
      int num_total_naughty_children,
      int num_total_nice_children,
      int num_total_adults
      );

   void draw();
};



