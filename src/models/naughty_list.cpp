


#include <models/naughty_list.h>



NaughtyList::Kid::Kid(std::string name)
   : name(name)
   , scene_id(-1)
   , killed(false)
{}



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



NaughtyList::NaughtyList()
   : kids()
{
   _initialize_kids_names();
}



