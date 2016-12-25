


#include <factories/scene_factory.h>

#include <factories/entity_factory.h>
#include <entities/entity_base.h>



float SceneFactory::door_notch_x(int pos)
   // door_notch_x is a convience function for easily
   // getting an x coordintate for placing a door
{
   float door_spacing = ONE_SCREEN_WIDTH / 6.0;
   return door_spacing + (door_spacing * 2) * pos;
}



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
   EntityFactory::create_door1(scene, door_notch_x(0), FLOOR_TOP, "A", 999, "A");

   // items
   EntityFactory::create_club_item(scene, 900, 565);

   return scene;
}



Scene *SceneFactory::create_scene_by_id(int scene_id)
{
   Scene *scene = nullptr;

   switch (scene_id)
   {
   case 0: scene = SceneFactory::create_scene_0(); break;
   case 1: scene = SceneFactory::create_scene_1(); break;
   case 2: scene = SceneFactory::create_scene_2(); break;
   case 3: scene = SceneFactory::create_scene_3(); break;
   case 4: scene = SceneFactory::create_scene_4(); break;
   case 5: scene = SceneFactory::create_scene_5(); break;
   case 6: scene = SceneFactory::create_scene_6(); break;
   case 7: scene = SceneFactory::create_scene_7(); break;
   case 8: scene = SceneFactory::create_scene_8(); break;
   case 9: scene = SceneFactory::create_scene_9(); break;
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



