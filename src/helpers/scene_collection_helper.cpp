


#include <helpers/scene_collection_helper.h>



SceneCollectionHelper::SceneCollectionHelper(Scene *scene)
   : scene(scene)
{}


std::vector<EntityBase *> SceneCollectionHelper::get_all_entities()
{
   return scene->get_flat_list_of_descendants<EntityBase>();
}



std::vector<KidEntity *> SceneCollectionHelper::get_kids()
{
   return ElementID::recast_collection<KidEntity>(scene->find_all_descendants("type", "kid"));
}



std::vector<DamageZoneEntity *> SceneCollectionHelper::get_damage_zones()
{
   return ElementID::recast_collection<DamageZoneEntity>(scene->find_all_descendants("type", "damage_zone"));
}



KrampusEntity *SceneCollectionHelper::get_krampus()
{
   return static_cast<KrampusEntity *>(scene->find_first_descendant("type", "krampus"));
}



