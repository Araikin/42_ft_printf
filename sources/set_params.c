/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 13:29:56 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/23 17:04:24 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_flags(char *params, t_format *data, int *pos)
{
	while (params[*pos] && is_flag(params[*pos]))
	{
		if (params[*pos] == '-')
			data->flags |= MINUS;
		else if (params[*pos] == '+')
			data->flags |= PLUS;
		else if (params[*pos] == '0')
			data->flags |= ZERO;
		else if (params[*pos] == '#')
			data->flags |= HASH;
		else if (params[*pos] == ' ')
			data->flags |= SPACE;
		*pos += 1;
	}
}

void	set_width(char *params, t_format *data, int *pos)
{
	int	width;

	width = 0;
	while (params[*pos] && is_digit(params[*pos]))
	{
		width = width * 10 + params[*pos] - '0';
		*pos += 1;
	}
	data->width = width;
}

void	set_specifier(char *params, t_format *data)
{
	int	i;

	i = 0;
	while (params[i] && !is_specifier(params[i]))
		i++;
	if (is_specifier(params[i]))
		data->specifier = params[i];
}
