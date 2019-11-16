#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <stdio.h>

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "libft/libft.h"

# define PLUS	1
# define MINUS	2
# define HASH	4
# define SPACE	8
# define ZERO	16

typedef struct		s_fmt
{
	char			specifier;
	unsigned int	length : 5;
	unsigned int	flags : 5; // '0' '-' '+' ' ' '#'
	int				precision;
	int				width;
}					t_fmt;

typedef struct		s_dt
{
	char			specifier;
	int				(*func)(va_list, t_fmt);
}					t_dt;

t_dt				g_dt[];

int					ft_printf(const char *fmt, ...);
void				proc_fmt(va_list *argp, char *fmt, int *i, int *num);
t_fmt				*init_fmt(void);

#endif
