


#include <entities/entity_base.h>
#include <helpers/scene_collision_helper.h>
#include <models/scene.h>
#include <algorithm>



Scene::Scene()
   : ElementID(nullptr)
{}



Scene::~Scene()
{
}



void Scene::update_all()
{
   SceneCollisionHelper collision_helper(this);
   collision_helper.resolve_collisions();

   for (auto &descendant : find_all_descendants("can_be_deleted"))
      delete descendant;
}



void Scene::draw_all()
{
   // for rendering, all entities need to be sorted as a flat list based on their y position

   std::vector<EntityBase *> entities = get_flat_list_of_descendants<EntityBase>();

   std::sort(entities.begin(), entities.end(),[](const EntityBase *a, const EntityBase *b)
         { return a->place.position.y < b->place.position.y; }
      );

   for (auto &entity : entities) entity->draw();
}



