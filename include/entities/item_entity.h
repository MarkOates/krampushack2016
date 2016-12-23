#pragma once



#include <entities/entity_base.h>



class ItemEntity : public EntityBase
{
public:
   ItemEntity(ElementID *parent, ALLEGRO_BITMAP *image, std::string item_type, float x, float y);
};



