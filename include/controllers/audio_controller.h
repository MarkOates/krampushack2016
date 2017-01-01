#pragma once



#include <allegro_flare/objects/sound_object.h>



class AudioController
{
private:
   Sound game_show_music;
   Sound haunting_music;
   int current_music_track_num;

public:
   AudioController();
   ~AudioController();

   void play_game_show_music();
   void play_haunting_music();

   void stop_all();

   void play_audio_track_by_id(int id);
};



