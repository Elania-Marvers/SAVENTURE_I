#include "lib.hpp"

panda_window::panda_window(int width, int height, const char *name)
  : _window(sf::VideoMode(width, height), name), _width(width), _height(height), _winSize(width * height)
{
  _background.create(_width, _height, panda_set_color(RED));
  _texture.loadFromImage(_background);
  _spr.setTexture(_texture);

  sf::Image icon;
  icon.loadFromFile("ressources/icon.png"); // File/Image/Pixel
  _window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

panda_window::~panda_window()
{
}

bool panda_window::isOpen(void)
{
  return _window.isOpen();
}

void panda_window::clear(void)
{
  _window.clear();
}


void panda_window::display(void)
{
  _texture.loadFromImage(_background);
  _spr.setTexture(_texture);
  _window.draw(_spr);
  _window.display();
}


void panda_window::event(void)
{
  while (_window.pollEvent(_event))
    {
      (_event.type == sf::Event::Closed) ? _window.close() : GO_ON(); // to close the window
      (_event.type == sf::Event::KeyPressed) ? (_event.key.code == sf::Keyboard::Escape) ? _window.close() : GO_ON() : GO_ON(); // To close the window with escape
    }
}


int panda_window::getWidth(void) const
{
  return _width;
}

int panda_window::getHeight(void) const
{
  return _height;
}

int panda_window::getWinSize(void) const
{
  return _winSize;
}


void panda_window::setPixel(t_panda_position pos, unsigned int color)
{
  _background.setPixel(pos.x, pos.y, panda_set_color(color));
}

void panda_window::setPixel(t_panda_accurate_position pos, unsigned int color)
{
  _background.setPixel((int) pos.x, (int) pos.y, panda_set_color(color));
}

void panda_window::setLine(t_panda_position *pos, unsigned int color)
{
  t_panda_accurate_position draw = {(double) pos[0].x, (double) pos[1].x};
  t_panda_accurate_position vec = {((double) pos[1].x - (double) pos[0].x), ((double) pos[1].y - (double) pos[0].y)};
  t_panda_position memory = {(int) draw.x, (int) draw.y};
  double ratio = (std::abs(vec.x) > std::abs(vec.y)) ? 1.0 / ((double) std::abs(vec.x)) : 1.0 / ((double) std::abs(vec.y));
  for (double a = 0.0; a <= 1; a += ratio)
    {
      draw = {	(double) pos[0].x + vec.x * a,
		(double) pos[0].y + vec.y * a,};
      if ((int) draw.x != memory.x || (int) draw.y != memory.y)
	setPixel(draw, color);
      memory = {(int) draw.x, (int) draw.y};
    }  
}



