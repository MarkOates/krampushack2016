#pragma once



#include <allegro_flare/objects/bitmap_object.h>
#include <allegro_flare/placement2d.h>
#include <allegro_flare/element_id.h>



class EntityBase : public ElementID
{
public:
   placement2d place;
   placement2d velocity;
   BitmapObject bitmap;

   EntityBase(ElementID *parent, std::string type, float x, float y);
   ~EntityBase();

   virtual void update();
   virtual void draw();
};



