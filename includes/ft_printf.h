/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:40:51 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/21 18:05:18 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "../libft/libft.h"

# define PLUS	1
# define MINUS	2
# define HASH	4
# define SPACE	8
# define ZERO	16

# define L		1
# define LL		2
# define H		4
# define HH		8

# define SPECS	"cspdDiouUxXfZ%"

typedef struct		s_format
{
	char			specifier;
	int				length : 4;
	int				flags : 5;
	int				precision;
	int				width;
}					t_format;

typedef int			t_specifiers(va_list *argp, t_format *data);

int					ft_printf(const char *format, ...);
int					print_format(char c);
int					clear_format(t_format *data);

int					parse_format(va_list *argp, char *format, int *i);
t_format			*initialize_format(void);

int					c_specifier(va_list *argp, t_format *data);

#endif
