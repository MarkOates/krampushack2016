


#include <factories/storyboard_factory.h>



StoryboardScreen *StoryboardFactory::create_opening_storyboard_screen(Display *display)
{
   std::vector<std::string> pages;

   pages.push_back("Oh no!\n\nThere has been a big Christmas mix up this year and Krampus accidentally got the wrong list of Naughty kids.");
   pages.push_back("What's even worse is that it's already Christmas Eve!\n\nKrampus needs to punish all the naughty kids or it'll be a Christmas disaster!");
   pages.push_back("Your task:\n\nTravel around Krampus cavern, find out who the naughty kids are, and deliver their well deserved Christmas punishment.");
   pages.push_back("Use the ARROW KEYS and SPACEBAR to play.  Once you get the legendary Stone of Defiance, you can activate it by pressing the R key.");
   pages.push_back("And one last thing!");
   pages.push_back("Good Luck!");

   StoryboardScreen *storyboard_screen = new StoryboardScreen(display, pages);
   return storyboard_screen;
}



