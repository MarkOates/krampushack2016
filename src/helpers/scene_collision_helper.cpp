


#include <helpers/scene_collision_helper.h>

#include <entities/damage_zone_entity.h>
#include <entities/entity_base.h>
#include <entities/kid_entity.h>
#include <entities/krampus_entity.h>
#include <helpers/scene_collection_helper.h>



SceneCollisionHelper::SceneCollisionHelper(Scene *scene)
   : scene(scene)
{}



void SceneCollisionHelper::resolve_collisions()
{
   if (!scene) return;

   SceneCollectionHelper collections(scene);

   for (auto &entity : collections.get_all_entities())
      entity->update();

   std::vector<KidEntity *> kids = collections.get_kids();

   // damage zone <-> kid collisions
   for (auto &damage_zone : collections.get_damage_zones())
   {
      for (auto &kid : kids)
      {
         if (damage_zone->collides(*kid))
         {
            std::cout << "col!";
            kid->flag_for_deletion();
         }
      }
   }
};



