#pragma once



#include <entities/entity_base.h>

#include <allegro_flare/shader.h>
#include <sprite_sheet.h>



enum behavior_t
{
   BEHAVIOR_ADULT,
   BEHAVIOR_NAUGHTY,
   BEHAVIOR_NICE
};



class KidEntity : public EntityBase
{
private:
   behavior_t behavior;
   std::string name;
   float walk_speed;
   Shader *flat_color_shader;
   float identity_reveal_counter;
   ALLEGRO_COLOR get_identity_color();
   float get_identity_tint_intensity();

public:
   KidEntity(ElementID *parent, SpriteSheet *sprite_sheet, Shader *flat_color_shader, float x, float y, std::string name, behavior_t behavior);
   virtual ~KidEntity();

   void update() override;
   void draw() override;

   void stand_still();
   void walk_up();
   void walk_down();
   void walk_left();
   void walk_right();

   void reveal_identity();
};



