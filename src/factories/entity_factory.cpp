


#include <factories/entity_factory.h>
#include <entities/background_entity.h>
#include <entities/damage_zone_entity.h>
#include <entities/kid_entity.h>
#include <entities/krampus_entity.h>



EntityFactory *EntityFactory::get_instance()
{
   if (!instance) instance = new EntityFactory();
   return instance;
}



EntityFactory::EntityFactory()
   : character_sprite_sheet("sprites_grid-04.png", 32, 32, 6, 6, 3)
{}



EntityBase *EntityFactory::create_random_kid(ElementID *parent, float x, float y)
{
   return new KidEntity(parent, &get_instance()->character_sprite_sheet, x, y);
}



EntityBase *EntityFactory::create_krampus(ElementID *parent, float x, float y)
{
   return new KrampusEntity(parent, &get_instance()->character_sprite_sheet, x, y);
}



EntityBase *EntityFactory::create_krampus_attack_damage_zone(ElementID *parent, float x, float y, float w, float h)
{
   return new DamageZoneEntity(parent, "krampus_damage_zone", x, y, w, h);
}



EntityBase *EntityFactory::create_background(ElementID *parent, ALLEGRO_BITMAP *bmp, float x, float y)
{
   return new BackgroundEntity(parent, bmp, x, y);
}



EntityFactory *EntityFactory::instance = nullptr;



