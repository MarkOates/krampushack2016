


#include <entities/item_entity.h>



ItemEntity::ItemEntity(ElementID *parent, ALLEGRO_BITMAP *bmp, std::string item_type, float x, float y)
   : EntityBase(parent, "item", x, y)
{
   place.size = vec2d(80, 20);
   bitmap.bitmap(bmp);
   bitmap.align(0.5, 1.0);
   bitmap.scale(2.0, 2.0);

   set("item_type", item_type);
}



