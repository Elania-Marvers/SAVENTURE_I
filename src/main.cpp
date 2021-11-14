#include "lib.hpp"




int main(void)
{
  srand(time(NULL));
  panda_window win(800, 800, "SFML PANDA");




  
  while (win.isOpen())
    {



      
      t_panda_position pos;
      pos = {rand() % win.getWidth(), rand() % win.getHeight()};
      //      win.setPixel(pos, PDA_COLOR(rand()%255, rand()%255, rand()%255, 128));
      win.setCircle(pos, rand()%100, PDA_COLOR(rand()%255, rand()%255, rand()%255, rand()%255));
      

            
      t_panda_position drawer[2];
      drawer[0] = {rand() % win.getWidth(), rand() % win.getHeight()};
      drawer[1] = {rand() % win.getWidth(), rand() % win.getHeight()};      
      //win.setLine(drawer, rand());
      //win.setRect(drawer, PDA_COLOR(rand()%255, rand()%255, rand()%255, rand()%255));
      
      //      sleep(1);
      win.event();
      win.clear();
      win.display();
    }

  return 0;
}
