


#include <factories/entity_factory.h>



EntityFactory *EntityFactory::get_instance()
{
   if (!instance) instance = new EntityFactory();
   return instance;
}



EntityFactory::EntityFactory()
   : character_sprite_sheet("sprites_grid-02b.png", 32, 32, 6, 6, 3)
{}



EntityBase *EntityFactory::create_random_kid(ElementID *parent, float x, float y)
{
   EntityBase *kid = new EntityBase(parent, "kid", x, y);
   kid->place.size = vec2d(60, 30);
   kid->bitmap.bitmap(get_instance()->character_sprite_sheet.get_sprite(random_int(0, 16)));
   kid->bitmap.align(0.5, 1.0);
   kid->bitmap.scale(2.0, 2.0);

   return kid;
}



EntityBase *EntityFactory::create_krampus(ElementID *parent, float x, float y)
{
   EntityBase *krampus = new EntityBase(parent, x, y);
   krampus->set("type", "kid");
   krampus->place.size = vec2d(120, 30);
   krampus->bitmap.bitmap(get_instance()->character_sprite_sheet.get_sprite(18));
   krampus->bitmap.align(0.5, 1.0);
   krampus->bitmap.scale(2.0, 2.0);

   return krampus;
}



EntityFactory *EntityFactory::instance = nullptr;



