#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft/libft.h"

# define PLUS	1
# define MINUS	2
# define HASH	4
# define SPACE	8
# define ZERO	16
//# define ASTER	32
//# define DOLLAR 64

typedef struct		s_format
{
	char			specifier;
	unsigned int	length : 5;
	unsigned int	flags : 5; // '0' '-' '+' ' ' '#'  // '*' '$'
	int				precision;
	int				width;
}					t_format;

int					ft_printf(const char *format, ...);

#endif
