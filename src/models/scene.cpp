


#include <models/entity_base.h>
#include <models/scene.h>



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
   for (auto &descendant : get_flat_list_of_descendants<EntityBase>())
      descendant->draw();
}



