


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
   EntityFactory::create_door1(scene, 200, 465, "A", 999, "A");

   // items
   EntityFactory::create_club_item(scene, 900, 565);

   return scene;
}



Scene *SceneFactory::create_scene_by_id(int scene_id)
{
   Scene *scene = nullptr;

   switch (scene_id)
   {
   case 999: scene = SceneFactory::create_test_scene(); break;
   default: break;
   }

   // player
   EntityFactory::create_krampus(scene, 600, 600);

   return scene;
}



Scene *SceneFactory::create_scene_0()
{
   Scene *scene = _create_scene_by_dimentions(2);
   return scene;
}



Scene *SceneFactory::create_scene_1()
{
   Scene *scene = _create_scene_by_dimentions(5);
   return scene;
}



Scene *SceneFactory::create_scene_2()
{
   Scene *scene = _create_scene_by_dimentions(2);
   return scene;
}



Scene *SceneFactory::create_scene_3()
{
   Scene *scene = _create_scene_by_dimentions(2);
   return scene;
}



Scene *SceneFactory::create_scene_4()
{
   Scene *scene = _create_scene_by_dimentions(1);
   return scene;
}



Scene *SceneFactory::create_scene_5()
{
   Scene *scene = _create_scene_by_dimentions(1);
   return scene;
}



Scene *SceneFactory::create_scene_6()
{
   Scene *scene = _create_scene_by_dimentions(1);
   return scene;
}



Scene *SceneFactory::create_scene_7()
{
   Scene *scene = _create_scene_by_dimentions(3);
   return scene;
}



Scene *SceneFactory::create_scene_8()
{
   Scene *scene = _create_scene_by_dimentions(1);
   return scene;
}



Scene *SceneFactory::create_scene_9()
{
   Scene *scene = _create_scene_by_dimentions(9);
   return scene;
}



