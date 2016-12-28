#pragma once



#include <models/inventory.h>



class HUD
{
private:
   int player_health;
   int player_max_health;
   Inventory *player_inventory;
   int num_alive_nice_children;
   int num_alive_naughty_children;
   int num_alive_adults;

public:
   HUD(int player_health, int player_max_health, Inventory *player_inventory, int num_alive_naughty_children, int num_alive_nice_children, int num_alive_adults);

   void draw();
};



