


#include <models/entity_base.h>
#include <models/scene.h>
#include <algorithm>



Scene::Scene()
   : ElementID(nullptr)
{}



void Scene::update_all()
{
   for (auto &descendant : get_flat_list_of_descendants<EntityBase>())
      descendant->update();
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



