#pragma once



#include <entities/entity_base.h>



class DoorEntity : public EntityBase
{
public:
   DoorEntity(ElementID *parent, ALLEGRO_BITMAP *door_img, float x, float y);
};



