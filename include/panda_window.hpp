class panda_window
{
private:
  sf::RenderWindow	_window;
  sf::Sprite		_spr;
  sf::RenderTexture	_pixelarray;
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

  void clear_pixelarray(unsigned int);
  void setPixel(t_panda_position, unsigned int);
  void setLine(t_panda_position *, unsigned int);
  void setRect(t_panda_position *pos, unsigned int color);  
  void setCircle(t_panda_position, int, unsigned int);  
};
