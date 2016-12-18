#pragma once



#include <sprite_sheet.h>

#include <models/entity_base.h>



class EntityFactory
{
private:
   SpriteSheet character_sprite_sheet;
   static EntityFactory *instance;
   static EntityFactory *get_instance();

   EntityFactory();
   ~EntityFactory();

public:
   static EntityBase *create_random_kid(ElementID *parent, float x, float y);
   static EntityBase *create_krampus(ElementID *parent, float x, float y);
};



