/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:01:32 by asultanb          #+#    #+#             */
/*   Updated: 2019/12/05 17:09:15 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_sign_f(t_format *data, int space, int sign)
{
	if (space)
		(data->flags & PLUS) ? ft_putchar('+') : ft_putchar(' ');
	(sign == -1) ? ft_putchar('-') : ft_putstr("");
}

int	fraction_len(float f)
{
	if (f - (int)f == 0.000000)
		return ((int)f);
	return (fraction_len(f * 10));
}

int		f_prec_zero(t_format *data, long int n, int sign)
{
	char	flag;
	int		space;
	int		len;

	len = ft_numlen((unsigned long long)(n * sign), 10);
	space = (n >= 0 && (data->flags & SPACE || data->flags & PLUS)) ? 1 : 0;
	flag = (data->flags & ZERO && !(data->flags & MINUS)) ? '0' : ' ';
	data->w_rem = data->width - len - ((n < 0) ? 1 : 0) - space;
	data->w_rem = (data->w_rem < 0) ? 0 : data->w_rem;
	if (data->flags & MINUS)
	{
		print_sign_f(data, space, sign);
		putnbr_ll('f', (unsigned long long)(n * sign), 10);
	}
	(flag == '0')  ? print_sign_f(data, space, sign) : ft_putstr("");
	print_rem(data->w_rem, flag);
	if (!(data->flags & MINUS))
	{
		(flag == ' ') ? print_sign_f(data, space, sign) : ft_putstr("");
		putnbr_ll('f', (unsigned long long)(n * sign), 10);
	}
	len = len + ((sign == -1) ? 1 : 0) + space + data->w_rem;
	return (len);
}

int		f_prec(t_format *data, int len, long double f, int sign)
{
	char	flag;
	int		space;
	int		x;
	int		i;

	i = 10;
	space = (sign == 1 && (data->flags & SPACE || data->flags & PLUS)) ? 1 : 0;
	flag = (data->flags & ZERO && !(data->flags & MINUS)) ? '0' : ' ';
	x = fraction_len(f - (long int)f);
	data->p_rem = (data->p_rem > ft_numlen((unsigned long long)n, 10)) 
	printf("%i\n", x);

	return (len + 1 + ((sign == -1) ? 1 : 0));
}

int		handle_f(va_list *argp, t_format *data)
{
	long double	f;
	int			sign;
	int			len;
	
	f = (data->length & UL) ? va_arg(*argp, long double) : va_arg(*argp, double);
	sign = (f < 0) ? -1 : 1;
	data->p_rem = (data->prec == 0 && data->prec != -1) ? 6 : data->prec;
	if (data->prec == -1)
		return (f_prec_zero(data, (long int)(f + (0.5 * sign)), sign));
	len = ft_numlen((unsigned long long)((long int)f * sign), 10);
	return (f_prec(data, len, f, sign));
}
