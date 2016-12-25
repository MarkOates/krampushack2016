


#include <models/camera.h>



Camera::Camera(Display *display, EntityBase *target)
   : place(0, 0, display->width(), display->height())
   , target(target)
{
   place.align = vec2d(0.5, 0);
}



void Camera::set_target(EntityBase *new_target)
{
   target = new_target;
}



void Camera::update()
{
   if (target)
      place.x = target->place.x;
}



void Camera::start_transform()
{
   place.start_transform();
}



void Camera::restore_transform()
{
   place.restore_transform();
}



