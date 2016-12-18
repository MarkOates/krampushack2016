#pragma once



#include <models/entity_base.h>
#include <sprite_sheet.h>



class KrampusEntity : public EntityBase
{
public:
   KrampusEntity(ElementID *parent, SpriteSheet *sprite_sheet, float x, float y);
};



