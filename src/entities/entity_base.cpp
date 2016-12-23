


#include <entities/entity_base.h>



EntityBase::EntityBase(ElementID *parent, std::string type, float x, float y)
   : ElementID(parent)
   , place(x, y, 20, 10)
   , velocity()
   , bitmap(nullptr)
{
   set("type", type);
   velocity.scale = vec2d(0, 0);
   velocity.align = vec2d(0, 0);
}



EntityBase::~EntityBase()
{}



void EntityBase::update()
{}



void EntityBase::flag_for_deletion()
{
   set("can_be_deleted");
}



void EntityBase::draw()
{
   place.start_transform();
   //al_draw_rectangle(0, 0, place.size.x, place.size.y, color::red, 2.0);
   bitmap.position(place.size.x/2, place.size.y/2);
   bitmap.draw();
   place.restore_transform();
}



bool EntityBase::collides(const EntityBase &other)
{
   float h_width = place.size.x * 0.5;
   float h_height = place.size.y * 0.5;

   // this will not account for rotation or anything fancy.
   // it's an unofficial ballpark close enough for jazz doodad:

   return other.place.collide(place.x, place.y, h_height, h_width, h_height, h_width);
}



