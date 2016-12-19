


#include <entities/kid_entity.h>



KidEntity::KidEntity(ElementID *parent, SpriteSheet *sprite_sheet, float x, float y)
   : EntityBase(parent, "kid", x, y)
{
   place.size = vec2d(60, 30);
   bitmap.bitmap(sprite_sheet->get_sprite(random_int(0, 16)));
   bitmap.align(0.5, 1.0);
   bitmap.scale(2.0, 2.0);
}



KidEntity::~KidEntity()
{
}



