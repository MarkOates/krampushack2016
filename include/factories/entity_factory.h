#pragma once



#include <sprite_sheet.h>

#include <entities/entity_base.h>



class EntityFactory
{
private:
   SpriteSheet character_sprite_sheet;
   ALLEGRO_BITMAP *background1;
   ALLEGRO_BITMAP *door1;
   static EntityFactory *instance;
   static EntityFactory *get_instance();

   EntityFactory();
   ~EntityFactory();

public:
   static EntityBase *create_random_kid(ElementID *parent, float x, float y);
   static EntityBase *create_krampus(ElementID *parent, float x, float y);
   static EntityBase *create_krampus_attack_damage_zone(ElementID *parent, float x, float y, float w, float h);
   static EntityBase *create_background1(ElementID *parent, float x, float y);
   static EntityBase *create_door1(ElementID *parent, float x, float y);
};



