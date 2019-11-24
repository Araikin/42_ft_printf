/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:01:21 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/23 17:01:25 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	adjust_width_c(t_format *data, char c)
{
	int		width;
	char	flag;

	width = data->width - 1;
	flag = (data->flags & ZERO && !(data->flags & MINUS)) ? '0' : ' ';
	if (data->flags & MINUS)
	{
		ft_putchar(c);
		while (width--)
			ft_putchar(flag);
	}
	else if (data->width > 0)
	{
		while (width--)
			ft_putchar(flag);
		ft_putchar(c);
	}
	else
		ft_putchar(c);
}
