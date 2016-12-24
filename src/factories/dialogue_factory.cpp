


#include <factories/dialogue_factory.h>

#include <allegro_flare/framework.h>
#include <models/item_dialogue.h>



DialogueFactory::DialogueFactory()
   : item_sprite_sheet("sprites_grid-05.png", 32, 32, 6, 6, 3)
   , dialogue_font(Framework::font("ChronoTrigger.ttf 60"))
{
}



DialogueFactory::~DialogueFactory()
{
}



DialogueFactory *DialogueFactory::get_instance()
{
   if (!instance) instance = new DialogueFactory();
   return instance;
}



ItemDialogue DialogueFactory::build_collected_item_dialog(int item_type)
{
   ALLEGRO_DISPLAY *display = al_get_current_display();
   int dialogue_x = al_get_display_width(display)/2;
   int dialogue_y = al_get_display_height(display)/4;
   int dialogue_w = 800;
   int dialogue_h = 200;
   ALLEGRO_BITMAP *item_bitmap = get_instance()->item_sprite_sheet.get_sprite(23);
   std::vector<std::string> dialogue = {"You picked up an item!"};

   ItemDialogue item_dialogue = ItemDialogue(dialogue_x, dialogue_y, dialogue_w, dialogue_h, item_bitmap, dialogue);

   return item_dialogue;
}



DialogueFactory *DialogueFactory::instance = nullptr;



