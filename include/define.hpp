# define			BLACK			((uint32_t) PDA_COLOR(255, 0, 0, 0))

# define			RED			((uint32_t) PDA_COLOR(255, 255, 0, 0))
# define			GREEN			((uint32_t) PDA_COLOR(255, 0, 255, 0))
# define			BLUE			((uint32_t) PDA_COLOR(255, 0, 0, 255))

# define			PURPLE			((uint32_t) PDA_COLOR(255, 255, 0, 255))
# define			TEAL			((uint32_t) PDA_COLOR(255, 0, 255, 255))
# define			YELLOW			((uint32_t) PDA_COLOR(255, 255, 255, 0))

# define			WHITE			((uint32_t) PDA_COLOR(255, 255, 255, 255))

# define			PINK			((uint32_t)0xFF7777FF)

# define			PINK2			((uint32_t)0xFFB469FF)

# define			PDA_TO_ALPHA(a)			(((a) & 0xFF) << (ALPHA_CMP * 8))
# define			PDA_TO_RED(a)			(((a) & 0xFF) << (RED_CMP * 8))
# define			PDA_TO_GREEN(a)			(((a) & 0xFF) << (GREEN_CMP * 8))
# define			PDA_TO_BLUE(a)			(((a) & 0xFF) << (BLUE_CMP * 8))
# define			PDA_GET_COLOR(c)			((c) & ~PDA_TO_ALPHA(255))
# define			PDA_ALPHA(a, c)			(PDA_TO_ALPHA(a) | PDA_GET_COLOR(c))
/*# define			PDA_COLOR(a, r, g, b)			\
  (PDA_TO_ALPHA(a) | PDA_TO_RED(r) | PDA_TO_GREEN(g) | PDA_TO_BLUE(b))*/
# define			PDA_ALPHA_GRAY(a, g)		\
  PDA_COLOR(a, g, g, g)
# define			PDA_GRAY(g)				\
  PDA_COLOR(255, g, g, g)


# define			PDA_COLOR(a, r, g, b)		\
  sf::Color(r, g, b, a).toInteger()
