


#include <helpers/scene_collision_helper.h>

#include <entities/damage_zone_entity.h>
#include <entities/entity_base.h>
#include <entities/kid_entity.h>
#include <entities/krampus_entity.h>
#include <helpers/scene_collection_helper.h>



SceneCollisionHelper::SceneCollisionHelper(Scene *scene)
   : scene(scene)
   , collections(scene)
{}



void SceneCollisionHelper::resolve_collisions()
{
   if (!scene) return;

   for (auto &entity : collections.get_all_entities())
      entity->update();

   limit_sprites_to_world_bounds();
   check_damage_zones_on_children();
};



void SceneCollisionHelper::limit_sprites_to_world_bounds()
{
   float min_y, max_y;
   scene->get_y_bounds(&min_y, &max_y);

   for (auto &entity : collections.get_entities_bound_in_world())
   {
      if (entity->place.y < min_y) entity->place.y = min_y;
      if (entity->place.y > max_y) entity->place.y = max_y;
   }
}



void SceneCollisionHelper::check_damage_zones_on_children()
{
   std::vector<KidEntity *> kids = collections.get_kids();

   // damage zone <-> kid collisions
   for (auto &damage_zone : collections.get_damage_zones())
   {
      for (auto &kid : kids)
      {
         if (damage_zone->is_dealing_damage() && damage_zone->collides(*kid))
         {
            kid->flag_for_deletion();
         }
      }
   }
}



