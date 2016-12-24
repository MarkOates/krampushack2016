#pragma once



class GamePlayScreen;

class GamePlayScreenStateHelper
{
private:
   GamePlayScreen *game_play_screen;
   float state_counter;

public:
   GamePlayScreenStateHelper(GamePlayScreen *game_play_screen);

   void set_state(int new_state);
   void update_state();
   void draw_state();
};



