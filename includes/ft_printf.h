/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:40:51 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/23 15:09:57 by asultanb         ###   ########.fr       */
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


# define MINUS	1
# define ZERO	2
# define PLUS	4
# define HASH	8
# define SPACE	16


# define L		1
# define LL		2
# define H		4
# define HH		8
# define UL		16

# define SPECS	"cspdDiouUxXfZ%"

typedef struct		s_format
{
	char			specifier;
	int				length : 5;
	int				flags : 5;
	int				precision;
	int				width;
}					t_format;

typedef int			t_specifiers(va_list *argp, t_format *data);

int					ft_printf(const char *format, ...);
int					print_format(char c);
int					clear_format(t_format *data);
t_format			*initialize_format(void);

int					parse_format(va_list *argp, char *format, int *i);
void				set_params(t_format *data, char *format, int *i);
char				*get_all_params(char *format, int i);
int					apply_params(va_list *argp, t_format *data);

void				set_flags(char *params, t_format *data, int *pos);
void				set_width(char *params, t_format *data, int *pos);
void				set_precision(char *params, t_format *data, int *pos);
void				set_length(char *params, t_format *data, int *pos);
void				set_specifier(char *params, t_format *data, int *pos);

int					is_flag(char c);
int					is_specifier(char c);
int					is_digit(char c);
int					is_length(char *params, int i);

int					c_specifier(va_list *argp, t_format *data);

void				adjust_width_c(t_format *data, char c);

#endif
