


#include <factories/entity_factory.h>



EntityFactory *EntityFactory::get_instance()
{
   if (!instance) instance = new EntityFactory();
   return instance;
}



EntityFactory::EntityFactory()
   : character_sprite_sheet("character_sprite_sheet.png")
{}



EntityBase *EntityFactory::create_random_kid(ElementID *parent, float x, float y)
{
   EntityBase *kid = new EntityBase(parent, "kid", x, y);
   kid->place.size = vec2d(60, 30);
   kid->bitmap.bitmap(get_instance()->character_sprite_sheet.get_sprite(random_int(0, 16)));

   return kid;
}



EntityFactory *EntityFactory::instance = nullptr;



