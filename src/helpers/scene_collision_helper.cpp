


#include <entities/entity_base.h>
#include <helpers/scene_collision_helper.h>



SceneCollisionHelper::SceneCollisionHelper(Scene *scene)
   : scene(scene)
{}



void SceneCollisionHelper::resolve_collisions()
{
   if (!scene) return;

   for (auto &entity : scene->get_flat_list_of_descendants<EntityBase>())
      entity->update();
};



