


#include <models/naughty_list.h>



NaughtyList::Kid::Kid(std::string name)
   : name(name)
   , scene_id(-1)
   , behavior()
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



NaughtyList::NaughtyList()
   : kids()
{}



