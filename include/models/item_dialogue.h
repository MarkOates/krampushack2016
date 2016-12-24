#pragma once



#include <allegro_flare/objects/bitmap_object.h>
#include <vector>
#include <string>



class ItemDialogue
{
private:
   placement2d place;
   std::vector<std::string> pages;
   ALLEGRO_FONT *font;
   BitmapObject bitmap;

public:
   ItemDialogue(float x, float y, float w, float h, ALLEGRO_BITMAP *item_bitmap, std::vector<std::string> pages);

   void draw(int page_num);
   int get_num_pages();
};



