#include "lib.hpp"

panda_window::panda_window(int width, int height, const char *name)
  : _window(sf::VideoMode(width, height), name), _width(width), _height(height), _winSize(width * height)
{
  _pixelarray.create(_width, _height);
  _pixelarray.clear(sf::Color::Red);

  sf::Image icon;
  icon.loadFromFile("ressources/icon.png"); // File/Image/Pixel
  _window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


  _window.setFramerateLimit(60);
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
  _spr.setTexture(_pixelarray.getTexture());
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
  sf::Vertex line[] =
    {
      sf::Vertex(sf::Vector2f(pos.x, pos.y), panda_set_color(color), sf::Vector2f(pos.x, pos.y)),
      sf::Vertex(sf::Vector2f(pos.x + 1, pos.y + 1), panda_set_color(color), sf::Vector2f(pos.x + 1, pos.y + 1))
    };

  _pixelarray.draw(line, 2, sf::Lines);
}

void panda_window::setLine(t_panda_position *pos, unsigned int color)
{
  sf::Vertex line[] =
    {
      sf::Vertex(sf::Vector2f(pos[0].x, pos[0].y), panda_set_color(color), sf::Vector2f(pos[0].x, pos[0].y)),
      sf::Vertex(sf::Vector2f(pos[1].x, pos[1].y), panda_set_color(color), sf::Vector2f(pos[1].x, pos[1].y))
    };

  _pixelarray.draw(line, 2, sf::Lines);
}



void panda_window::clear_pixelarray(unsigned int color)
{
  _pixelarray.clear(panda_set_color(color));
}


void panda_window::setRect(t_panda_position *pos, unsigned int color)
{
  sf::RectangleShape rectangle;
  rectangle.setPosition(sf::Vector2f(pos[0].x, pos[0].y));
  rectangle.setFillColor(panda_set_color(color));
  rectangle.setSize(sf::Vector2f(pos[1].x - pos[0].x, pos[1].y - pos[0].y));
  _pixelarray.draw(rectangle);
}

void panda_window::setCircle(t_panda_position pos, int radius, unsigned int color)
{
  sf::CircleShape shape;
  shape.setRadius(radius);
  shape.setPosition(sf::Vector2f(pos.x, pos.y));
  shape.setFillColor(panda_set_color(color));
  _pixelarray.draw(shape);
}
