


#include <factories/scene_factory.h>

#include <allegro_flare/framework.h>
#include <factories/entity_factory.h>
#include <entities/entity_base.h>



Scene *SceneFactory::create_test_scene()
{
   Scene *scene = new Scene();
   ALLEGRO_BITMAP *background_image = Framework::bitmap("background-1-02.png");

   for (unsigned i=0; i<2; i++)
      EntityFactory::create_background(scene, background_image, i*480, 100);

   for (unsigned i=0; i<20; i++)
      EntityFactory::create_random_kid(scene, random_float(200, 900), random_float(400, 600));

   EntityFactory::create_krampus(scene, 300, 600);

   return scene;
}



