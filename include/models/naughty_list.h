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

   void _initialize_kids_names();

public:
   NaughtyList();
   ~NaughtyList();
};



