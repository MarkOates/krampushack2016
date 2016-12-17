


#include <factories/scene_factory.h>

#include <factories/entity_factory.h>
#include <models/entity_base.h>



Scene *SceneFactory::create_test_scene()
{
   Scene *scene = new Scene();

   for (unsigned i=0; i<20; i++)
   {
      EntityFactory::create_random_kid(scene, random_float(200, 900), random_float(400, 600));
   }

   return scene;
}



