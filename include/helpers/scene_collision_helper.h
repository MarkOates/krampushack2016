#pragma once



#include <models/scene.h>
#include <helpers/scene_collection_helper.h>



class SceneCollisionHelper
{
private:
   Scene *scene;
   SceneCollectionHelper collections;

public:
   SceneCollisionHelper(Scene *scene);

   void resolve_collisions();
   void limit_sprites_to_world_bounds();
};



