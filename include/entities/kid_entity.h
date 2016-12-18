#pragma once



#include <entities/entity_base.h>
#include <sprite_sheet.h>



class KidEntity : public EntityBase
{
public:
   KidEntity(ElementID *parent, SpriteSheet *sprite_sheet, float x, float y);
};



