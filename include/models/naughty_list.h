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
      bool is_naughty();
      bool is_nice();
      bool is_adult();
      bool is_alive();
   };

   std::vector<Kid> kids;

public:
   NaughtyList();
};



