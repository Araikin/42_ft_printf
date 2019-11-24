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

	c = va_arg(*argp, int);
	if (data->specifier == 'c')
		adjust_width_c(data, (char)c);
	if (data->width == 0)
		data->width = 1;
	return (data->width);
}

int		s_specifier(va_list *argp, t_format *data)
{
	char *str;

	str = va_arg(*argp, int);
}
