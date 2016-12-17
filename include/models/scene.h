#pragma once



#include <allegro_flare/element_id.h>



class Scene : public ElementID
{
public:
   Scene();
   ~Scene();

   void update_all();
   void draw_all();
};



