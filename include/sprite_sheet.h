#pragma once



#include <allegro5/allegro.h>
#include <string>
#include <vector>



class SpriteSheet
{
private:
   ALLEGRO_BITMAP *atlas;
   std::vector<ALLEGRO_BITMAP *> sprites;
   bool _create_sub_sprites();
   int sprite_width;
   int sprite_height;
   int num_sprites_x;
   int num_sprites_y;

public:
   SpriteSheet(std::string filename);
   ~SpriteSheet();

   ALLEGRO_BITMAP *get_sprite(int index);
};



