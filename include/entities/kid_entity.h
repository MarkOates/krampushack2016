#pragma once



#include <entities/entity_base.h>
#include <sprite_sheet.h>



enum behavior_t
{
   BEHAVIOR_ADULT,
   BEHAVIOR_NAUGHTY,
   BEHAVIOR_NICE
};



class KidEntity : public EntityBase
{
private:
   behavior_t behavior;
   std::string name;

public:
   KidEntity(ElementID *parent, SpriteSheet *sprite_sheet, float x, float y, std::string name, behavior_t behavior);
   virtual ~KidEntity();
};



