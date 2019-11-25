/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 13:32:55 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/23 17:11:55 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		c_specifier(va_list *argp, t_format *data)
{
	int c;
	int	width;
	int	flag;

	c = va_arg(*argp, int);
	flag = (data->flags & ZERO && !(data->flags & MINUS)) ? '0' : ' ';
	if (data->specifier == 'c')
	{
		if (data->width == 0)
			data->width = 1;
		width = data->width - 1;
		if (data->flags & MINUS)
			ft_putchar(c);
		while (width--)
			ft_putchar(flag);
		if (data->width > 0 && !data->flags)
			ft_putchar(c);
	}
	return (data->width);
}

int		s_specifier(va_list *argp, t_format *data)
{
	char *str;

	str = va_arg(*argp, char *);
	if (data->specifier == 's')
		adjust_width(data, str);
	return (0);
}
