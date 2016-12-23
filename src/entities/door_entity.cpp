


#include <entities/door_entity.h>



DoorEntity::DoorEntity(ElementID *parent, ALLEGRO_BITMAP *door_img, float x, float y)
   : EntityBase(parent, "door", x, y)
{
   bitmap.bitmap(door_img);
   bitmap.align(0.5, 1.0);
   bitmap.scale(1.5, 1.2);
   place.size = vec2d(80, 5);
}



