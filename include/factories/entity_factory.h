#pragma once



#include <sprite_sheet.h>

#include <entities/entity_base.h>



class EntityFactory
{
private:
   SpriteSheet character_sprite_sheet;
   ALLEGRO_BITMAP *background1;
   ALLEGRO_BITMAP *background2;
   ALLEGRO_BITMAP *background3;
   ALLEGRO_BITMAP *background4;
   ALLEGRO_BITMAP *background5;
   ALLEGRO_BITMAP *background6;
   ALLEGRO_BITMAP *door1;
   ALLEGRO_BITMAP *club_item;
   static EntityFactory *instance;
   static EntityFactory *get_instance();

   EntityFactory();
   ~EntityFactory();

public:
   static EntityBase *create_random_kid(ElementID *parent, float x, float y);
   static EntityBase *create_krampus(ElementID *parent, float x, float y);
   static EntityBase *create_krampus_attack_damage_zone(ElementID *parent, float x, float y, float w, float h);
   static EntityBase *create_door1(ElementID *parent, float x, float y, std::string name, int destination_scene, std::string destination_door_name);
   static EntityBase *create_club_item(ElementID *parent, float x, float y);
   static EntityBase *create_stone_of_defiance_item(ElementID *parent, float x, float y);
   static EntityBase *create_naughty_list_item(ElementID *parent, float x, float y);
   static EntityBase *create_key_item(ElementID *parent, float x, float y);

   static EntityBase *create_background1(ElementID *parent, float x, float y);
   static EntityBase *create_background2(ElementID *parent, float x, float y);
   static EntityBase *create_background3(ElementID *parent, float x, float y);
   static EntityBase *create_background4(ElementID *parent, float x, float y);
   static EntityBase *create_background5(ElementID *parent, float x, float y);
   static EntityBase *create_background6(ElementID *parent, float x, float y);
};



