# define			BLACK			((uint32_t)(255 << (ALPHA_CMP * 8)))

# define			RED			((uint32_t)(BLACK | (255 << RED_CMP * 8)))
# define			GREEN			((uint32_t)(BLACK | (255 << GREEN_CMP * 8)))
# define			BLUE			((uint32_t)(BLACK | (255 << BLUE_CMP * 8)))

# define			PURPLE			((uint32_t)(RED | BLUE))
# define			TEAL			((uint32_t)(GREEN | BLUE))
# define			YELLOW			((uint32_t)(RED | GREEN))

# define			WHITE			((uint32_t)(RED | GREEN | BLUE))

# define			PINK			((uint32_t)0xFF7777FF)

# define			PINK2			((uint32_t)0xFFB469FF)

# define			PDA_TO_ALPHA(a)			(((a) & 0xFF) << (ALPHA_CMP * 8))
# define			PDA_TO_RED(a)			(((a) & 0xFF) << (RED_CMP * 8))
# define			PDA_TO_GREEN(a)			(((a) & 0xFF) << (GREEN_CMP * 8))
# define			PDA_TO_BLUE(a)			(((a) & 0xFF) << (BLUE_CMP * 8))
# define			PDA_GET_COLOR(c)			((c) & ~PDA_TO_ALPHA(255))
# define			PDA_ALPHA(a, c)			(PDA_TO_ALPHA(a) | PDA_GET_COLOR(c))
# define			PDA_COLOR(a, r, g, b)		\
  (PDA_TO_ALPHA(a) | PDA_TO_RED(r) | PDA_TO_GREEN(g) | PDA_TO_BLUE(b))
# define			PDA_ALPHA_GRAY(a, g)		\
  PDA_COLOR(a, g, g, g)
# define			PDA_GRAY(g)				\
  PDA_COLOR(255, g, g, g)
