


#include <allegro_flare/framework.h>
#include <allegro_flare/image_processing.h>
#include <factories/entity_factory.h>
#include <entities/background_entity.h>
#include <entities/door_entity.h>
#include <entities/damage_zone_entity.h>
#include <entities/item_entity.h>
#include <entities/kid_entity.h>
#include <entities/krampus_entity.h>
#include <item_type_nums.h>



EntityFactory *EntityFactory::get_instance()
{
   if (!instance) instance = new EntityFactory();
   return instance;
}



EntityFactory::EntityFactory()
   : character_sprite_sheet("sprites_grid-05.png", 32, 32, 6, 6, 3)
   , background1(nullptr)
   , door1(nullptr)
{
   background1 = create_pixel_perfect_scaled_render(Framework::bitmap("background-1-08.png"), 5);
   door1 = create_pixel_perfect_scaled_render(Framework::bitmap("door-1-02.png"), 5);
}



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



EntityBase *EntityFactory::create_background1(ElementID *parent, float x, float y)
{
   return new BackgroundEntity(parent, get_instance()->background1, x, y);
}



EntityBase *EntityFactory::create_door1(ElementID *parent, float x, float y)
{
   return new DoorEntity(parent, get_instance()->door1, x, y);
}



EntityBase *EntityFactory::create_club_item(ElementID *parent, float x, float y)
{
   return new ItemEntity(parent, get_instance()->character_sprite_sheet.get_sprite(23), ITEM_TYPE_CLUB, x, y);
}



EntityBase *EntityFactory::create_stone_of_defiance_item(ElementID *parent, float x, float y)
{
   return new ItemEntity(parent, get_instance()->character_sprite_sheet.get_sprite(24), ITEM_TYPE_STONE_OF_DEFIANCE, x, y);
}



EntityBase *EntityFactory::create_naughty_list_item(ElementID *parent, float x, float y)
{
   return new ItemEntity(parent, get_instance()->character_sprite_sheet.get_sprite(25), ITEM_TYPE_NAUGHTY_LIST, x, y);
}



EntityBase *EntityFactory::create_key_item(ElementID *parent, float x, float y)
{
   return new ItemEntity(parent, get_instance()->character_sprite_sheet.get_sprite(26), ITEM_TYPE_KEY, x, y);
}



EntityFactory *EntityFactory::instance = nullptr;



