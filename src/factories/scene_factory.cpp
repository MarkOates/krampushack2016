


#include <factories/scene_factory.h>

#include <models/entity_base.h>



Scene *SceneFactory::create_test_scene()
{
   Scene *scene = new Scene();

   for (unsigned i=0; i<20; i++)
   {
      new EntityBase(scene, "elem", random_float(0, 500), random_float(0, 500));
   }

   return scene;
}



