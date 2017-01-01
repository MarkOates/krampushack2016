#pragma once



#include <sprite_sheet.h>
#include <models/item_dialogue.h>



class DialogueFactory
{
private:
   SpriteSheet item_sprite_sheet;
   ALLEGRO_FONT *dialogue_font;
   static DialogueFactory *instance;
   static DialogueFactory *get_instance();

   DialogueFactory();
   ~DialogueFactory();

public:
   static ItemDialogue build_collected_item_dialog(int item_type);
   static ItemDialogue build_dialogue(std::string message);
};



