


#include <factories/scene_factory.h>

#include <allegro_flare/framework.h>
#include <allegro_flare/image_processing.h>
#include <factories/entity_factory.h>
#include <entities/entity_base.h>



Scene *SceneFactory::create_test_scene()
{
   Scene *scene = new Scene();

   // background
   // note, this bitmap dangles, and is never deleted
   ALLEGRO_BITMAP *original_bitmap = Framework::bitmap("background-1-02.png");
   ALLEGRO_BITMAP *scaled_background = create_pixel_perfect_scaled_render(original_bitmap, 5);

   for (unsigned i=0; i<2; i++)
      EntityFactory::create_background(scene, scaled_background, i*al_get_bitmap_width(scaled_background), 100);

   // enemies
   for (unsigned i=0; i<20; i++)
      EntityFactory::create_random_kid(scene, random_float(200, 900), random_float(400, 600));

   // player
   EntityFactory::create_krampus(scene, 300, 600);

   return scene;
}



