#pragma once



#include <allegro_flare/display.h>
#include <allegro_flare/motion.h>
#include <entities/entity_base.h>



class Camera
{
private:
   placement2d place;
   EntityBase *target;
   ALLEGRO_COLOR overlay_color;
   Motion motion;

public:
   Camera(Display *display, EntityBase *target);

   void set_target(EntityBase *new_target=nullptr);

   void update(float max_x);
   void start_transform();
   void restore_transform();
   void fade_to_black(float duration=0.4);
   void fade_to_clear(float duration=0.4);

   void draw_overlay();
};



