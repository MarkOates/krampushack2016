#pragma once



#include <entities/kid_entity.h>
#include <string>
#include <vector>



class NaughtyList
{
private:
   class Kid
   {
   public:
      std::string name;
      int scene_id;
      behavior_t behavior;
      bool killed;
      Kid(std::string name);
   };

   std::vector<Kid> kids;

   void _initialize_kids_names();
   void _shuffle_kids();
   void _distribute_kid_behavior();

public:
   NaughtyList();
   ~NaughtyList();
};



