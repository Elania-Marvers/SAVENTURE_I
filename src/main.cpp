#include "lib.hpp"

static void print_jeu (panda_window *win, int w, int h, int *map);



int main(void)
{
  srand(time(NULL));
  panda_window win(800, 800, "SFML PANDA");


  
  while (win.isOpen())
    {
      win.clear_pixelarray(RED);

      win.event();
      win.clear();
      win.display();
    }

  return 0;
}
