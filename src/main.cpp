#include "lib.hpp"




int main(void)
{
  srand(time(NULL));
  panda_window win(800, 800, "SFML PANDA");




  
  while (win.isOpen())
    {

      win.event();

      /*
      t_panda_position pos;
      pos = {rand() % win.getWidth(), rand() % win.getHeight()};
      win.setPixel(pos, BLACK);
      */

      /*
      t_panda_position drawer[2];
      drawer[0] = {rand() % win.getWidth(), rand() % win.getHeight()};
      drawer[1] = {rand() % win.getWidth(), rand() % win.getHeight()};      
      win.setLine(drawer, rand());
      */


      
      
      win.clear();
      win.display();
    }

  return 0;
}
