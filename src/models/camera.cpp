


#include <models/camera.h>



Camera::Camera(Display *display, EntityBase *target)
   : place(0, 0, display->width(), display->height())
   , target(target)
{
   place.anchor = vec2d(place.w/2, place.h/2);
}



void Camera::set_target(EntityBase *new_target)
{
   target = new_target;
}



void Camera::update(float max_x)
{
   if (target) place.x = place.w/2 - target->place.x;

   // prevent from moving beyond the size of the room
   float screen_width = (256*5);
   float room_width = max_x - screen_width;
   if (place.x > 0) place.x = 0; // left edge
   if (place.x < -room_width) place.x = -room_width; // right edge
}



void Camera::start_transform()
{
   place.start_transform();
}



void Camera::restore_transform()
{
   place.restore_transform();
}



