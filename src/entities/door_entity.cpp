


#include <entities/door_entity.h>



DoorEntity::DoorEntity(ElementID *parent, ALLEGRO_BITMAP *door_img, float x, float y)
   : EntityBase(parent, "door", x, y)
{
   bitmap.bitmap(door_img);
}



