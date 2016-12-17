


#include <sprite_sheet.h>

#include <allegro_flare/framework.h>



SpriteSheet::SpriteSheet(std::string filename)
   : atlas(Framework::bitmap(filename))
   , sprites()
   , sprite_width(32)
   , sprite_height(32)
   , num_sprites_x(6)
   , num_sprites_y(6)
{
   _create_sub_sprites();
}



bool SpriteSheet::_create_sub_sprites()
{
   if (!atlas) return false;

   for (unsigned cursor_y=0; cursor_y<num_sprites_y; cursor_y++)
      for (unsigned cursor_x=0; cursor_x<num_sprites_x; cursor_x++)
      {
         ALLEGRO_BITMAP *sub_bitmap = al_create_sub_bitmap(atlas,
               cursor_x * sprite_width,
               cursor_y * sprite_height,
               sprite_width,
               sprite_height);

         sprites.push_back(sub_bitmap);
      }

   return true;
}



SpriteSheet::~SpriteSheet()
{
}



ALLEGRO_BITMAP *SpriteSheet::get_sprite(int index)
{
   if (index < 0 || index >= sprites.size()) return nullptr;
   return sprites[index];
}


