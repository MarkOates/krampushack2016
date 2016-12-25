#pragma once



#include <models/inventory.h>



class HUD
{
private:
   int player_health;
   int player_max_health;
   Inventory *player_inventory;
   int num_good_children;
   int num_naughty_children;

public:
   HUD(int player_health, int player_max_health, Inventory *player_inventory, int num_good_children, int num_naughty_children);

   void draw();
};



