/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:01:32 by asultanb          #+#    #+#             */
/*   Updated: 2019/12/04 17:32:43 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		handle_f(va_list *argp, t_format *data)
{
	long double	f;
	int			len;
	int			sign;
	
	if (data->length & UL)
		f = va_arg(*argp, long double);
	else
		f = va_arg(*argp, double);
	sign = (f < 0) ? -1 : 1;
	len = ft_fnumlen((long double)(f * sign));	
	printf("len: %i\n", len);
	return (0);
}
