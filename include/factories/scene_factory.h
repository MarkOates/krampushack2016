#pragma once



#include <models/scene.h>



#define ONE_SCREEN_WIDTH (256*5)



class SceneFactory
{
private:
   static Scene *_create_scene_by_dimentions(int screen_widths);

public:
   static Scene *create_test_scene();

   static Scene *create_scene_by_id(int scene_id);

   static Scene *create_scene_0();
   static Scene *create_scene_1();
   static Scene *create_scene_2();
   static Scene *create_scene_3();
   static Scene *create_scene_4();
   static Scene *create_scene_5();
   static Scene *create_scene_6();
   static Scene *create_scene_7();
   static Scene *create_scene_8();
   static Scene *create_scene_9();
};



