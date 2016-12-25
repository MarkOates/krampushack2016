#pragma once



#include <allegro_flare/display.h>
#include <entities/entity_base.h>



class Camera
{
private:
   placement2d place;
   EntityBase *target;

public:
   Camera(Display *display, EntityBase *target);

   void set_target(EntityBase *new_target=nullptr);

   void update(float max_x);
   void start_transform();
   void restore_transform();
};



