


#include <models/entity_base.h>



EntityBase::EntityBase(ElementID *parent, std::string type, float x, float y)
   : ElementID(parent)
   , place(x, y, 20, 10)
   , velocity()
   , bitmap(nullptr)
   , type(type)
{
   velocity.scale = vec2d(0, 0);
   velocity.align = vec2d(0, 0);

   bitmap.align(0.5, 1.0);
   bitmap.scale(5, 5);
}



EntityBase::~EntityBase()
{}



void EntityBase::update()
{
   place += velocity;
}



void EntityBase::draw()
{
   place.start_transform();
   al_draw_rectangle(0, 0, place.size.x, place.size.y, color::red, 2.0);
   bitmap.position(place.size.x/2, place.size.y/2);
   bitmap.draw();
   place.restore_transform();
}


