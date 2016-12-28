#pragma once



#include <models/inventory.h>
#include <models/naughty_list.h>



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
   HUD(Inventory *player_inventory, NaughtyList *naughty_list);

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



