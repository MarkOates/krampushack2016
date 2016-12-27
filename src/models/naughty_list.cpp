


#include <models/naughty_list.h>



NaughtyList::Kid::Kid(std::string name)
   : name(name)
   , scene_id(-1)
   , killed(false)
{}



NaughtyList::NaughtyList()
   : kids(
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

      // KrampusHack participants
      , {"Mark Oates"}
      , {"Eric Johnson"}
      , {"Edgar Reynaldo"}
      , {"Elias"}
      , {"Amarillion"}
      , {"SiegeLord"}
      , {"Vanneto"}
      , {"m c"}
      , {"Takaaki Furukawa"}
      , {"Derezo"}

      // Also joined the discussion in
      // https://www.allegro.cc/forums/thread/616642
      , {"GullRaDriel"}
      , {"Felix-The-Ghost"}
      , {"bamccaig"}
      , {"Specter Phoenix"}
      , {"MiquelFire"}
      , {"Onewing"}
      , {"LennyLen"}

      // Other notable a.cc members
      , {"Johan Halmén"}
      , {"torhu"}
      , {"LennyLen"}
      , {"AMCerasoli"}
      , {"Steve Terry"}
      , {"Ariesnl"}
      , {"Thomas Fjellstrom"}
      , {"Dennis"}
      , {"Gideon Weems"}
      , {"Polybios"}
      , {"Rodolfo Lam"}
      , {"Don Freeman"}
      , {"Bob Keane"}
      , {"anto80"}
      , {"Neil Roy"}
      , {"relpatseht"}
      , {"Bruce Perry"}
      , {"Chris Katko"}
      , {"Matthew Leverton"}
      , {"jmasterx"}
      , {"Peter Hull"}
      , {"OnlineCop"}
      , {"Niunio"}
      , {"DanielH"}
      , {"Audric"}
      , {"Paul whoknows"}
      , {"Aaron Bolyard"}

      })
{
}



