#pragma once



#include <models/scene.h>
#include <entities/entity_base.h>
#include <entities/kid_entity.h>
#include <entities/krampus_entity.h>
#include <entities/damage_zone_entity.h>



class SceneCollectionHelper
{
private:
   Scene *scene;

public:
   SceneCollectionHelper(Scene *scene);

   std::vector<EntityBase *> get_all_entities();
   std::vector<KidEntity *> get_kids();
   std::vector<DamageZoneEntity *> get_damage_zones();
   KrampusEntity *get_krampus();
};



