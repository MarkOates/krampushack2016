


#include <entities/kid_entity.h>



KidEntity::KidEntity(ElementID *parent, SpriteSheet *sprite_sheet, float x, float y, std::string name, behavior_t behavior)
   : EntityBase(parent, "kid", x, y)
   , name(name)
   , behavior(behavior)
{
   place.size = vec2d(60, 30);
   bitmap.bitmap(sprite_sheet->get_sprite(random_int(0, 16)));
   bitmap.align(0.5, 1.0);
   bitmap.scale(2.0, 2.0);

   set("bound_in_world");
}



KidEntity::~KidEntity()
{
}



