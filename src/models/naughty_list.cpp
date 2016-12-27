


#include <models/naughty_list.h>

#include <algorithm>



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



void NaughtyList::_initialize_kids_names()
{
   kids =
      { {"Sally"}
      , {"Jill"}
      , {"Tara"}
      , {"Erica"}
      , {"Emily"}
      , {"Tanya"}
      , {"Gloria"}
      , {"Elise"}
      , {"Florence"}
      , {"Sarah"}
      , {"Karen"}
      , {"Mary"}
      , {"Wendy"}
      , {"Lily"}
      , {"Lisa"}
      , {"Vivian"}
      , {"Ingrid"}
      , {"Nichole"}
      , {"Penelope"}
      , {"Noel"}
      , {"Penny"}
      , {"Hellen"}
      , {"Kelly"}
      , {"Doris"}
      , {"Olga"}
      , {"Christine"}
      , {"Claire"}
      , {"Stacy"}
      , {"Edward"}
      , {"Donald"}
      , {"Homer"}
      , {"Matt"}
      , {"Tommy"}
      , {"Thomas"}
      , {"Tim"}
      , {"Timmy"}
      , {"Toby"}
      , {"Billy"}
      , {"Bruce"}
      , {"Chris"}
      , {"Donny"}
      , {"Frankie"}
      , {"Greg"}
      , {"Gorby"}
      , {"Hugo"}
      , {"George"}
      , {"Hamilton"}
      , {"Jeremy"}
      , {"Johnathan"}
      , {"Jack"}
      , {"Kirk"}
      , {"Michael"}
      , {"Norman"}
      , {"Nick"}
      , {"Patrick"}
      , {"Peter"}
      , {"Paul"}
      , {"Robert"}
      , {"Richard"}
      , {"Sam"}
      , {"Luther"}
      , {"Walter"}
      };
}



void NaughtyList::_shuffle_kids()
{
   std::random_shuffle(kids.begin(), kids.end());
}



void NaughtyList::_distribute_kid_behavior()
{
   _shuffle_kids();

   int total_kids = kids.size();

   for (unsigned i=0; i<kids.size(); i++)
   {
      if (i > total_kids*0.66) kids[i].behavior = BEHAVIOR_NICE;
      else if (i > total_kids*0.33) kids[i].behavior = BEHAVIOR_NAUGHTY;
      else kids[i].behavior = BEHAVIOR_ADULT;
   }

   _shuffle_kids();
}



NaughtyList::NaughtyList()
   : kids()
{
   _initialize_kids_names();
}



