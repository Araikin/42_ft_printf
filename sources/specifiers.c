/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:46:47 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/21 18:07:17 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		c_specifier(va_list *argp, t_format *data)
{
	char c;

	c = va_arg(*argp, int);
	if (data->specifier == 'c')
		ft_putchar(c);
	return (1);
}
