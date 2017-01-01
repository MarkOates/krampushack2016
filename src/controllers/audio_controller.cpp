


#include <controllers/audio_controller.h>

#include <allegro_flare/framework.h>
#include <music_track_nums.h>



AudioController::AudioController()
   : game_show_music(Framework::sample("369920__mrthenoronha__cartoon-game-theme-loop.wav"))
   , haunting_music(Framework::sample("haunting_atmosphere-01.wav"))
   , current_music_track_num(0)
{
   game_show_music.loop(true);
   haunting_music.loop(true);
}



AudioController::~AudioController()
{
   stop_all();
}



void AudioController::stop_all()
{
   haunting_music.stop();
   game_show_music.stop();
}



void AudioController::play_game_show_music()
{
   play_audio_track_by_id(GAME_SHOW_MUSIC);
}



void AudioController::play_haunting_music()
{
   play_audio_track_by_id(HAUNTING_MUSIC);
}



void AudioController::play_audio_track_by_id(int track_id)
{
   if (track_id == current_music_track_num) return;

   stop_all();
   current_music_track_num = track_id;

   switch (track_id)
   {
   case GAME_SHOW_MUSIC:
      game_show_music.play();
      break;
   case HAUNTING_MUSIC:
      haunting_music.play();
      break;
   default:
      break;
   }
}



