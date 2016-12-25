


#include <models/camera.h>



Camera::Camera(Display *display, EntityBase *target)
   : place(0, 0, display->width(), display->height())
   , target(target)
   , overlay_color(color::transparent)
   , motion()
{
   place.anchor = vec2d(place.w/2, place.h/2);
}



void Camera::set_target(EntityBase *new_target)
{
   target = new_target;
}



void Camera::update(float max_x)
{
   motion.update(al_get_time());

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



void Camera::draw_overlay()
{
   al_draw_filled_rectangle(0, 0, place.w, place.h, overlay_color);
}



void Camera::set_overlay_color(ALLEGRO_COLOR new_overlay_color)
{
   overlay_color = new_overlay_color;
}



void Camera::fade_to_black(float duration)
{
   motion.cmove_to(&overlay_color.r, 0, duration);
   motion.cmove_to(&overlay_color.g, 0, duration);
   motion.cmove_to(&overlay_color.b, 0, duration);
   motion.cmove_to(&overlay_color.a, 0, duration);
}



void Camera::fade_to_clear(float duration)
{
   motion.cmove_to(&overlay_color.r, 1.0, duration);
   motion.cmove_to(&overlay_color.g, 1.0, duration);
   motion.cmove_to(&overlay_color.b, 1.0, duration);
   motion.cmove_to(&overlay_color.a, 1.0, duration);
}



void Camera::set_zoom(float scale)
{
   place.scale.x = scale;
   place.scale.y = scale;
}



void Camera::zoom_to(float scale, float duration)
{
   motion.cmove_to(&place.scale.x, scale, duration);
   motion.cmove_to(&place.scale.y, scale, duration);
}



