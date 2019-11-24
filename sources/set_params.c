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

void	set_precision(char *params, t_format *data, int *pos)
{
	int	precision;

	precision = 0;
	if (params[*pos] && params[*pos] == '.')	
	{
		*pos += 1;
		while (params[*pos] && is_digit(params[*pos]))
		{
			precision = precision * 10 + (params[*pos] - '0');
			*pos += 1;
		}
	}
	data->precision = precision;
}

void	set_length(char *params, t_format *data, int *pos)
{
	int	result;

	result = 0;
	if (params[*pos] && params[*pos + 1])
	{
		result = is_length(params, *pos);
		if (result == 1)
			data->length |= L;
		else if (result == 2)
			data->length |= LL;
		else if (result == 3)
			data->length |= H;
		else if (result == 4)
			data->length |= HH;
		else if (result == 5)
			data->length |= UL;
	}
	if (result > 0 && result % 2 == 1)
		*pos += 1;
	else if (result > 0 && result % 2 == 0)
		*pos += 2;
}

void	set_specifier(char *params, t_format *data, int *pos)
{
	if (is_specifier(params[*pos]))
	{
		data->specifier = params[*pos];
		*pos += 1;
	}
}
