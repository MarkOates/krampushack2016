


#include <models/item_dialogue.h>

#include <allegro_flare/color.h>
#include <allegro_flare/framework.h>



ItemDialogue::ItemDialogue(float x, float y, float w, float h, ALLEGRO_BITMAP *item_bitmap, ALLEGRO_FONT *font, std::vector<std::string> pages)
   : place(x, y, w, h)
   , bitmap(item_bitmap)
   , font(font)
   , pages(pages)
{
   bitmap.align(0.5, 0.5);
   bitmap.position(30, 30);
   bitmap.rotation(0.15);
   bitmap.scale(1.2, 1.2);
}



void ItemDialogue::draw(int page_num)
{
   place.start_transform();

   // draw the background and frame
   al_draw_filled_rectangle(0, 0, place.w, place.h, color::black);
   al_draw_rectangle(0, 0, place.w, place.h, color::white, 5.0);

   // draw the item
   bitmap.draw();

   // draw the text
   if (font && page_num >= 0 && page_num < get_num_pages())
      al_draw_multiline_text(
            font,
            color::white,
            0,
            0,
            300,
            al_get_font_line_height(font),
            0,
            pages[page_num].c_str()
         );

   place.restore_transform();
}



int ItemDialogue::get_num_pages()
{
   return pages.size();
}



