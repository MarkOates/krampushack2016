


#include <factories/scene_factory.h>

#include <factories/entity_factory.h>
#include <entities/entity_base.h>



Scene *SceneFactory::create_test_scene()
{
   Scene *scene = new Scene();

   // background
   EntityFactory::create_background1(scene, 0, 100);
   EntityFactory::create_background1(scene, 750, 100);

   // enemies
   for (unsigned i=0; i<20; i++)
      EntityFactory::create_random_kid(scene, random_float(200, 900), random_float(400, 600));

   // player
   EntityFactory::create_krampus(scene, 300, 600);

   return scene;
}



