


#include <entities/entity_base.h>
#include <helpers/scene_collection_helper.h>
#include <helpers/scene_collision_helper.h>
#include <models/scene.h>
#include <algorithm>



Scene::Scene()
   : ElementID(nullptr)
   , floor_min_y(450)
   , floor_max_y(500)
{}



Scene::~Scene()
{
}



void Scene::set_y_bounds(float min_y, float max_y)
{
   floor_min_y = min_y;
   floor_max_y = max_y;
}



void Scene::get_y_bounds(float *min_y, float *max_y)
{
   *min_y = floor_min_y;
   *max_y = floor_max_y;
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
   SceneCollectionHelper collection_helper(this);

   for (auto &entity : collection_helper.get_all_entities_y_sorted())
      entity->draw();
}



