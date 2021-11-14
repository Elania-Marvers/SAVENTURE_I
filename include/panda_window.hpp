class panda_window
{
private:
  sf::RenderWindow	_window;
  sf::Image		_background;
  sf::Texture		_texture;
  sf::Sprite		_spr;
  int			_width,
			_height,
			_winSize;
  sf::Event		_event;
  
public:
  panda_window(int, int, const char *);
  ~panda_window();

  bool isOpen(void);
  void clear(void);
  void display(void);
  void event(void);

  int getWidth(void) const;
  int getHeight(void) const;
  int getWinSize(void) const;

  void setPixel(t_panda_position, unsigned int);
  void setPixel(t_panda_accurate_position pos, unsigned int color);
  void setLine(t_panda_position *pos, unsigned int color);
  
};
