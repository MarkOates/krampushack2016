#pragma once



#include <models/scene.h>



class SceneCollisionHelper
{
private:
   Scene *scene;

public:
   SceneCollisionHelper(Scene *scene);

   void resolve_collisions();
};



