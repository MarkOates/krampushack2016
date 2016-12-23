#pragma once



#include <models/scene.h>



class SceneFactory
{
public:
   static Scene *create_test_scene();

   static Scene *create_scene_by_id(int scene_id);
};



