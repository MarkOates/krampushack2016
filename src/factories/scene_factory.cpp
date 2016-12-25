


#include <factories/scene_factory.h>

#include <factories/entity_factory.h>
#include <entities/entity_base.h>



Scene *SceneFactory::_create_scene_by_dimentions(int screen_widths)
{
   Scene *scene = new Scene(ONE_SCREEN_WIDTH*screen_widths);

   // background
   for (unsigned i=0; i<screen_widths; i++)
      EntityFactory::create_background1(scene, i*ONE_SCREEN_WIDTH, 0);

   return scene;
}



Scene *SceneFactory::create_test_scene()
{
   Scene *scene = _create_scene_by_dimentions(2);

   // enemies
   for (unsigned i=0; i<20; i++)
      EntityFactory::create_random_kid(scene, random_float(200, 900), random_float(400, 600));

   // doors
   EntityFactory::create_door1(scene, 200, 465);

   // items
   EntityFactory::create_club_item(scene, 900, 565);

   // player
   EntityFactory::create_krampus(scene, 600, 600);

   return scene;
}



Scene *SceneFactory::create_scene_by_id(int scene_id)
{
   switch (scene_id)
   {
   case 1: return SceneFactory::create_test_scene(); break;
   default: break;
   }

   return nullptr;
}



