


#include <entities/damage_zone_entity.h>



DamageZoneEntity::DamageZoneEntity(ElementID *parent, std::string damage_zone_type, float x, float y, float w, float h)
   : EntityBase(parent, "damage_zone", x, y)
   , dealing_damage(true)
{
   place.size = vec2d(w, h);
   set("damage_zone_type", damage_zone_type);
}



DamageZoneEntity::~DamageZoneEntity()
{
}



void DamageZoneEntity::draw()
{
   EntityBase::draw();
}



void DamageZoneEntity::update()
{
   dealing_damage = false;
}



bool DamageZoneEntity::is_dealing_damage()
{
   return dealing_damage;
}



int DamageZoneEntity::get_damage(float x, float y)
{
   return 1;
}



