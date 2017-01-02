


#include <controllers/audio_controller.h>

#include <allegro_flare/framework.h>
#include <music_track_nums.h>



AudioController::AudioController()
   : game_show_music(Framework::sample("369920__mrthenoronha__cartoon-game-theme-loop.wav"))
   , storyboard_music(Framework::sample("storyboard_music.ogg"))
   , haunting_music(Framework::sample("haunting_atmosphere-01.wav"))
   , hurt_sound_effect(Framework::sample("217192__rt759__game-voice-3.wav"))
   , win_cheer_sound_effect(Framework::sample("win_cheer.ogg"))
   , fail_moan_sound_effect(Framework::sample("fail_moan.ogg"))
   , current_music_track_num(-1)
{
   game_show_music.loop(true);
   storyboard_music.loop(true);
   haunting_music.loop(true);
}



AudioController::~AudioController()
{
   stop_all();
}



void AudioController::stop_all()
{
   haunting_music.stop();
   storyboard_music.stop();
   game_show_music.stop();
   hurt_sound_effect.stop();
   win_cheer_sound_effect.stop();
   fail_moan_sound_effect.stop();
}



void AudioController::play_game_show_music()
{
   play_audio_track_by_id(GAME_SHOW_MUSIC);
}



void AudioController::play_storyboard_music()
{
   play_audio_track_by_id(STORYBOARD_MUSIC);
}



void AudioController::play_haunting_music()
{
   play_audio_track_by_id(HAUNTING_MUSIC);
}



void AudioController::play_hurt_sound_effect()
{
   play_sound_effect_by_id(HURT_SOUND_EFFECT);
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
   case STORYBOARD_MUSIC:
      storyboard_music.play();
      break;
   default:
      break;
   }
}



void AudioController::play_sound_effect_by_id(int track_id)
{
   switch (track_id)
   {
   case HURT_SOUND_EFFECT:
      hurt_sound_effect.play();
      break;
   case WIN_CHEER_SOUND_EFFECT:
      win_cheer_sound_effect.play();
      break;
   case FAIL_MOAN_SOUND_EFFECT:
      fail_moan_sound_effect.play();
      break;
   default:
      break;
   }
}



