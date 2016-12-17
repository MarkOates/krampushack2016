


#include <sprite_sheet.h>

#include <allegro_flare/framework.h>



SpriteSheet::SpriteSheet(std::string filename, int sprite_width, int sprite_height, int num_rows, int num_columns)
   : atlas(Framework::bitmap(filename))
   , sprites()
   , sprite_width(sprite_width)
   , sprite_height(sprite_height)
   , num_rows(num_rows)
   , num_columns(num_columns)
{
   _create_sub_sprites();
}



bool SpriteSheet::_create_sub_sprites()
{
   if (!atlas) return false;

   for (unsigned cursor_y=0; cursor_y<num_rows; cursor_y++)
      for (unsigned cursor_x=0; cursor_x<num_columns; cursor_x++)
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


