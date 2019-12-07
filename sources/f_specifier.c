/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:01:32 by asultanb          #+#    #+#             */
/*   Updated: 2019/12/06 17:49:28 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_sign_f(t_format *data, int space, int sign)
{
	if (space)
		(data->flags & PLUS) ? ft_putchar('+') : ft_putchar(' ');
	(sign == -1) ? ft_putchar('-') : ft_putstr("");
}

int		f_prec_zero(t_format *data, long long int n, int sign)
{
	char	flag;
	int		space;
	int		len;

	len = ft_numlen((unsigned long long)(n * sign), 10);
	space = (n >= 0 && (data->flags & SPACE || data->flags & PLUS)) ? 1 : 0;
	flag = (data->flags & ZERO && !(data->flags & MINUS)) ? '0' : ' ';
	data->w_rem = data->width - len - ((n < 0) ? 1 : 0) - space -
		((data->flags & HASH) ? 1 : 0);
	data->w_rem = (data->w_rem < 0) ? 0 : data->w_rem;
	if (data->flags & MINUS)
	{
		print_sign_f(data, space, sign);
		putnbr_ll('f', (unsigned long long)(n * sign), 10);
		(data->flags & HASH) ? ft_putchar('.') : ft_putstr("");
	}
	(flag == '0')  ? print_sign_f(data, space, sign) : ft_putstr("");
	print_rem(data->w_rem, flag);
	if (!(data->flags & MINUS))
	{
		(flag == ' ') ? print_sign_f(data, space, sign) : ft_putstr("");
		putnbr_ll('f', (unsigned long long)(n * sign), 10);
		(data->flags & HASH) ? ft_putchar('.') : ft_putstr("");
	}
	len = len + ((sign == -1) ? 1 : 0) + space + data->w_rem +
		((data->flags & HASH) ? 1 : 0);
	return (len);
}

void	print_f_prec(t_format *data, long double f, int sign)
{
	long double	x;
	int			prec;

	prec = data->prec;
	putnbr_ll('f', (unsigned long long)((long int)f * sign), 10);
	ft_putchar('.');
	x = (f - (long int)f) * (long double)sign;
	while (prec--)
	{
		x = x * 10;
		ft_putchar((int)x + '0');
		x -= (int)x;
	}
}

int		f_prec(t_format *data, int len, long double f, int sign)
{
	char				flag;
	int					space;
	int					i;

	i = 10;
	space = (sign == 1 && (data->flags & SPACE || data->flags & PLUS)) ? 1 : 0;
	flag = (data->flags & ZERO && !(data->flags & MINUS)) ? '0' : ' ';
	data->w_rem = data->width - data->prec - len - 1 - space - ((sign == -1) ? 1 : 0);
	data->w_rem = (data->w_rem < 0) ? 0 : data->w_rem;
	if (data->flags & MINUS)
	{
		print_sign_f(data, space, sign);
		print_f_prec(data, f, sign);
	}
	(flag == '0') ? print_sign_f(data, space, sign) : ft_putstr("");
	print_rem(data->w_rem, flag);
	if (!(data->flags & MINUS))
	{
		(flag == ' ') ? print_sign_f(data, space, sign) : ft_putstr("");
		print_f_prec(data, f, sign);
	}
	return (len + 1 + ((sign == -1) ? 1 : 0) + data->w_rem + space + data->prec);
}

int		handle_f(va_list *argp, t_format *data)
{
	long double	f;
	int			sign;
	int			len;
	long double	round;
	
	f = (data->length & UL) ? va_arg(*argp, long double) : va_arg(*argp, double);
	sign = (f < 0) ? -1 : 1;
	data->prec = (data->prec == 0) ? 6 : data->prec;
	if (data->prec == -1)
		return (f_prec_zero(data, (long long int)(f + (0.5 * (long double)sign)), sign));
	round = get_round(data->prec);
	f += (round * (long double)sign);
	len = ft_numlen((unsigned long long)((long int)f * sign), 10);
	return (f_prec(data, len, f, sign));
}
