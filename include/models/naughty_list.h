#pragma once



#include <entities/kid_entity.h>
#include <generators/kid_name_generator.h>
#include <string>
#include <vector>



class NaughtyList
{
public:
   class Kid
   {
   public:
      std::string name;
      int scene_id;
      behavior_t behavior;
      bool killed;
      Kid(std::string name, int scene_id, behavior_t behavoir);
      bool is_naughty();
      bool is_nice();
      bool is_adult();
      bool is_alive();
   };

private:
   std::vector<Kid> kids;

   KidNameGenerator kid_name_generator;
   Kid _build_kid(int scene_id);

public:
   NaughtyList();

   std::vector<Kid> get_alive_kids_for_scene(int scene);

   int get_num_alive_naughty_kids();
   int get_num_alive_nice_kids();
   int get_num_alive_adults();
};



