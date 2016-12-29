


#include <models/naughty_list.h>



NaughtyList::Kid::Kid(std::string name, int sprite_index, int scene_id, behavior_t behavior)
   : name(name)
   , scene_id(scene_id)
   , sprite_index(sprite_index)
   , behavior(behavior)
   , killed(false)
{}



behavior_t NaughtyList::Kid::get_behavior()
{
   return behavior;
}



std::string NaughtyList::Kid::get_name()
{
   return name;
}



int NaughtyList::Kid::get_sprite_index()
{
   return sprite_index;
}



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
   std::string name = "";
   int sprite_index = -1;
   behavior_t behavior = BEHAVIOR_NAUGHTY;
   std::vector<behavior_t> non_adult_behaviors = { BEHAVIOR_NAUGHTY, BEHAVIOR_NICE };

   // select a name and sprite index
   int kid_type = random_int(0, 2); // 0 = boy, 1 = girl, 2 = adult
   switch(kid_type)
   {
      case 0:
         name = kid_name_generator.get_boy_name();
         sprite_index = _get_random_sprite_for_boy();
         behavior = random_element<behavior_t>(non_adult_behaviors);
         break;
      case 1:
         name = kid_name_generator.get_girl_name();
         sprite_index = _get_random_sprite_for_girl();
         behavior = random_element<behavior_t>(non_adult_behaviors);
         break;
      case 2:
         name = random_bool() ? kid_name_generator.get_girl_name() : kid_name_generator.get_boy_name();
         sprite_index = _get_random_sprite_for_adult();
         behavior = BEHAVIOR_ADULT;
         break;
      default:
         break;
   }

   // select a random behavior
   return Kid(name, sprite_index, scene_id, behavior);
}



int NaughtyList::_get_random_sprite_for_boy()
{
   return 2;
}



int NaughtyList::_get_random_sprite_for_girl()
{
   return 3;
}



int NaughtyList::_get_random_sprite_for_adult()
{
   return 0;
}



NaughtyList::NaughtyList()
   : kids()
   , kid_name_generator()
{
   std::vector<std::pair<int, int>> scene_kids =
   {
   // {scene_id, num_of_kids}
      {1, 20},
      {2, 3},
      {3, 6},
      {5, 1},
      {6, 1},
      {7, 25}
   };

   // generate the kids for each scene
   for (unsigned i=0; i<scene_kids.size(); i++)
   {
      int scene_id = scene_kids[i].first;
      int num_kids = scene_kids[i].second;

      for (unsigned i=0; i<num_kids; i++)
         kids.push_back(_build_kid(scene_id));
   }
}



std::vector<NaughtyList::Kid> NaughtyList::get_alive_kids_for_scene(int scene)
{
   std::vector<Kid> results;

   for (auto &kid : kids)
      if (kid.is_alive() && kid.scene_id == scene) results.push_back(kid);

   return results;
}



int NaughtyList::get_num_alive_naughty_kids()
{
   int count = 0;

   for (auto &kid : kids)
      if (kid.is_alive() && kid.behavior == BEHAVIOR_NAUGHTY) count++;

   return count;
}



int NaughtyList::get_num_alive_nice_kids()
{
   int count = 0;

   for (auto &kid : kids)
      if (kid.is_alive() && kid.behavior == BEHAVIOR_NICE) count++;

   return count;
}



int NaughtyList::get_num_alive_adults()
{
   int count = 0;

   for (auto &kid : kids)
      if (kid.is_alive() && kid.behavior == BEHAVIOR_ADULT) count++;

   return count;
}



int NaughtyList::get_num_total_naughty_kids()
{
   int count = 0;

   for (auto &kid : kids) if (kid.behavior == BEHAVIOR_NAUGHTY) count++;

   return count;
}



int NaughtyList::get_num_total_nice_kids()
{
   int count = 0;

   for (auto &kid : kids) if (kid.behavior == BEHAVIOR_NICE) count++;

   return count;
}



int NaughtyList::get_num_total_adults()
{
   int count = 0;

   for (auto &kid : kids) if (kid.behavior == BEHAVIOR_ADULT) count++;

   return count;
}



bool NaughtyList::kill_kid_by_name(std::string name)
{
   Kid *found_kid = nullptr;

   // find the kid
   for (auto &kid : kids)
      if (kid.name == name)
      {
         found_kid = &kid;
         break;
      }

   if (found_kid && found_kid->is_alive())
   {
      found_kid->killed = true;
      return true;
   }

   return false;
}



