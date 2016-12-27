#pragma once



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
      bool killed;
      Kid(std::string name);
   };

   std::vector<Kid> kids;

public:
   NaughtyList();
   ~NaughtyList();
};



