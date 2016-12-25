#pragma once



#include <models/scene.h>



#define ONE_SCREEN_WIDTH (256*5)



class SceneFactory
{
public:
   static Scene *create_test_scene();

   static Scene *create_scene_by_id(int scene_id);
};



