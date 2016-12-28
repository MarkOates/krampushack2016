#pragma once



#include <models/inventory.h>
#include <models/naughty_list.h>



class HUD
{
private:
   Inventory *player_inventory;
   NaughtyList *naughty_list;
   int player_health;
   int player_max_health;

   BitmapObject chrome_bitmap;
   ALLEGRO_FONT *font;

public:
   HUD(Inventory *player_inventory, NaughtyList *naughty_list);

   void set_values(int player_health, int player_max_health);

   void draw();
};



