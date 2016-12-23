


#include <entities/background_entity.h>

#include <allegro_flare/image_processing.h>



BackgroundEntity::BackgroundEntity(ElementID *parent, ALLEGRO_BITMAP *al_bitmap, float x, float y)
   : EntityBase(parent, "background", x, y)
{
   place.align = vec2d(0.0, 0.0);
   ALLEGRO_BITMAP *scaled_bitmap = create_pixel_perfect_scaled_render(al_bitmap, 3);
   bitmap.bitmap(scaled_bitmap);
}



BackgroundEntity::~BackgroundEntity()
{
   al_destroy_bitmap(bitmap.get_bitmap());
}



void BackgroundEntity::draw()
{
   place.start_transform();
   bitmap.draw();
   place.restore_transform();
}



