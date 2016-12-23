


#include <entities/item_entity.h>



ItemEntity::ItemEntity(ElementID *parent, std::string item_type, float x, float y)
   : EntityBase(parent, "item", x, y)
{
   set("item_type", item_type);
}



