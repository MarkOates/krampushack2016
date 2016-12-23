#pragma once



#include <entities/entity_base.h>



class BackgroundEntity : public EntityBase
{
private:
   ALLEGRO_BITMAP *al_bitmap;

public:
   BackgroundEntity(ElementID *parent, ALLEGRO_BITMAP *al_bitmap, float x, float y);
   ~BackgroundEntity();

   void draw() override;
};



