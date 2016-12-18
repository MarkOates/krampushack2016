


#include <controllers/player_krampus_controller.h>



PlayerKrampusController::PlayerKrampusController()
   : krampus(nullptr)
{}



void PlayerKrampusController::set_krampus(KrampusEntity *new_krampus)
{
   krampus = new_krampus;
}



bool PlayerKrampusController::has_a_krampus()
{
   return krampus != nullptr;
}



void PlayerKrampusController::on_key_down(int al_keycode)
{
   if (!has_a_krampus()) return;

   switch(al_keycode)
   {
   case ALLEGRO_KEY_UP: krampus->walk_up(); break;
   case ALLEGRO_KEY_DOWN: krampus->walk_down(); break;
   case ALLEGRO_KEY_RIGHT: krampus->walk_right(); break;
   case ALLEGRO_KEY_LEFT: krampus->walk_left(); break;
   case ALLEGRO_KEY_SPACE: krampus->attack(); break;
   default: break;
   }
}



void PlayerKrampusController::on_key_up(int al_keycode)
{
   if (!has_a_krampus()) return;

   switch(al_keycode)
   {
   case ALLEGRO_KEY_UP: krampus->stand_still(); break;
   case ALLEGRO_KEY_DOWN: krampus->stand_still(); break;
   case ALLEGRO_KEY_RIGHT: krampus->stand_still(); break;
   case ALLEGRO_KEY_LEFT: krampus->stand_still(); break;
   default: break;
   }
}



