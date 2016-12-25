


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

   // doors
   EntityFactory::create_door1(scene, door_notch_x(4), FLOOR_TOP, "A", 1, "a");

   return scene;
}



Scene *SceneFactory::create_scene_1()
   // master corridor
{
   Scene *scene = _create_scene_by_dimentions(4);

   // doors
   EntityFactory::create_door1(scene, door_notch_x(0), FLOOR_TOP, "F", 2, "f");
   EntityFactory::create_door1(scene, door_notch_x(4), FLOOR_TOP, "E", 9, "e"); // big santa door
   EntityFactory::create_door1(scene, door_notch_x(7), FLOOR_TOP, "B", 3, "b");
   EntityFactory::create_door1(scene, door_notch_x(10), FLOOR_TOP, "a", 0, "A");

   return scene;
}



Scene *SceneFactory::create_scene_2()
{
   Scene *scene = _create_scene_by_dimentions(2);

   // doors
   EntityFactory::create_door1(scene, door_notch_x(0), FLOOR_TOP, "G", 4, "g");
   EntityFactory::create_door1(scene, door_notch_x(5), FLOOR_TOP, "f", 1, "F");

   return scene;
}



Scene *SceneFactory::create_scene_3()
{
   Scene *scene = _create_scene_by_dimentions(2);

   // doors
   EntityFactory::create_door1(scene, door_notch_x(0), FLOOR_TOP, "b", 1, "B");
   EntityFactory::create_door1(scene, door_notch_x(4), FLOOR_TOP, "C", 7, "c");
   EntityFactory::create_door1(scene, door_notch_x(5), FLOOR_TOP, "D", 5, "d");

   return scene;
}



Scene *SceneFactory::create_scene_4()
{
   Scene *scene = _create_scene_by_dimentions(1);

   // doors
   EntityFactory::create_door1(scene, door_notch_x(0), FLOOR_TOP, "g", 2, "G");
   EntityFactory::create_door1(scene, door_notch_x(1), FLOOR_TOP, "H", 6, "h");

   return scene;
}



Scene *SceneFactory::create_scene_5()
{
   Scene *scene = _create_scene_by_dimentions(1);

   // doors
   EntityFactory::create_door1(scene, door_notch_x(0), FLOOR_TOP, "d", 3, "D");

   return scene;
}



Scene *SceneFactory::create_scene_6()
{
   Scene *scene = _create_scene_by_dimentions(1);

   // doors
   EntityFactory::create_door1(scene, door_notch_x(0), FLOOR_TOP, "h", 4, "H");

   return scene;
}



Scene *SceneFactory::create_scene_7()
{
   Scene *scene = _create_scene_by_dimentions(3);

   // doors
   EntityFactory::create_door1(scene, door_notch_x(1), FLOOR_TOP, "D", 8, "d");
   EntityFactory::create_door1(scene, door_notch_x(6), FLOOR_TOP, "c", 3, "C");

   return scene;
}



Scene *SceneFactory::create_scene_8()
{
   Scene *scene = _create_scene_by_dimentions(1);

   // doors
   EntityFactory::create_door1(scene, door_notch_x(0), FLOOR_TOP, "d", 7, "D");

   return scene;
}



Scene *SceneFactory::create_scene_9()
{
   Scene *scene = _create_scene_by_dimentions(9);

   // doors
   EntityFactory::create_door1(scene, door_notch_x(4), FLOOR_TOP, "e", 1, "E");  // external big santa door

   return scene;
}



