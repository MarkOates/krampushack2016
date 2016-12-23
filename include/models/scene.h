#pragma once



#include <allegro_flare/element_id.h>



class Scene : public ElementID
{
private:
   float floor_min_y, floor_max_y;

public:
   Scene();
   ~Scene();

   void set_y_bounds(float min_y, float max_y);
   void get_y_bounds(float *min_y, float *max_y);

   void update_all();
   void draw_all();
};



