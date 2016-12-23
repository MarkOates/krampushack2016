#pragma once



#include <entities/entity_base.h>



class ItemEntity : public EntityBase
{
public:
   ItemEntity(ElementID *parent, std::string item_type, float x, float y);
};



