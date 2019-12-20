/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:40:51 by asultanb          #+#    #+#             */
/*   Updated: 2019/12/09 14:47:26 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

# define SPECS	"cspdDiouxXf%"

typedef struct		s_format
{
	int				length : 5;
	int				flags : 5;
	int				prec;
	int				width;
	int				p_rem;
	int				w_rem;
	char			spec;
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

int					handle_c(va_list *argp, t_format *data);
int					handle_s(va_list *argp, t_format *data);
void				adjust_p(t_format *data, char *str);
int					handle_p(va_list *argp, t_format *data);
int					handle_percent(va_list *argp, t_format *data);

int					adjust_di(t_format *data, int64_t n, int len);
int					handle_di(va_list *argp, t_format *data);
void				print_sign(t_format *data, int64_t n, int m, char flag);
void				di_minus(t_format *data, int64_t n);
void				di_nominus(t_format *data, int64_t n);

void				print_ox(t_format *data, uint64_t n);
void				ouxx_minus(t_format *data, uint64_t n, int base, char flag);
void				ouxx_nomin(t_format *data, uint64_t n, int base, char flag);
int					adjust_ouxx(t_format *data, uint64_t n, int len, int base);
int					handle_ouxx(va_list *argp, t_format *data);

int					handle_f(va_list *argp, t_format *data);
int					f_prec(t_format *data, int len, long double f, int sign);
void				print_f_prec(t_format *data, long double f);
int					f_prec_zero(t_format *data, long long int n, int sign,
					int len);
void				print_fraction(t_format *data, float f, int sign);

char				*itoa_base(unsigned long long n, int base, char c);
void				putnbr_ll(char specifier, unsigned long long n, int base);
void				print_rem(int rem, char c);
int					ft_numlen(unsigned long long n, int base);
long double			get_round(int precision);

int					ft_min(int a, int b);
int					ft_max(int a, int b);

#endif
