


#include <models/naughty_list.h>



NaughtyList::Kid::Kid(std::string name, int scene_id, behavior_t behavior)
   : name(name)
   , scene_id(scene_id)
   , behavior(behavior)
   , killed(false)
{}



bool NaughtyList::Kid::is_naughty()
{
   return behavior == BEHAVIOR_NAUGHTY;
}



bool NaughtyList::Kid::is_nice()
{
   return behavior == BEHAVIOR_NICE;
}



bool NaughtyList::Kid::is_adult()
{
   return behavior == BEHAVIOR_ADULT;
}



bool NaughtyList::Kid::is_alive()
{
   return !killed;
}



NaughtyList::Kid NaughtyList::_build_kid(int scene_id)
{
   // pull out a random name
   std::string name = random_bool() ? kid_name_generator.get_girl_name() : kid_name_generator.get_boy_name();

   // select a random behavior
   std::vector<behavior_t> behaviors = { BEHAVIOR_NAUGHTY, BEHAVIOR_NICE, BEHAVIOR_ADULT };
   behavior_t behavior = random_element<behavior_t>(behaviors);

   return Kid(name, scene_id, behavior);
}



NaughtyList::NaughtyList()
   : kids()
   , kid_name_generator()
{}



