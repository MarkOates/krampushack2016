


#include <entities/krampus_entity.h>



KrampusEntity::KrampusEntity(ElementID *parent, SpriteSheet *sprite_sheet, float x, float y)
   : EntityBase(parent, "krampus", x, y)
{
   place.size = vec2d(120, 30);
   bitmap.bitmap(sprite_sheet->get_sprite(18));
   bitmap.align(0.5, 1.0);
   bitmap.scale(2.0, 2.0);
}



