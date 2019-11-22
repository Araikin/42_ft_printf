/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:19:22 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/21 18:05:05 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_specifiers    *g_dispatch[] = {
	c_specifier,
};

int		is_specifier(char c)
{
	return (c == 'c');
}

void	get_specifier(char *params, t_format *data)
{
	int	pos = 0;
	while (params[pos] && !is_specifier(params[pos]))
		pos++;
	if (is_specifier(params[pos]))
		data->specifier = params[pos];
}

char	*get_all_params(char *format, int i)
{
	char	*params;
	int		pos;	

	pos = 0;
	while (format[i + pos] && !is_specifier(format[i + pos]))
		pos++;
	params = ft_strnew(pos + 1);
	pos = 0;
	while (format[i + pos])
	{
		if (!is_specifier(format[i + pos]))
			params[pos] = format[i + pos];
		else
		{
			params[pos] = format[i + pos];
			break ;
		}
		pos++;
	}
	return (params);
}

void	set_data(t_format *data, char *format, int *i)
{
	char *params;

	params = get_all_params(format, *i);
	get_specifier(params, data);
	*i += ft_strlen(params);
	ft_strdel(&params);
}

int		implement_data(va_list *argp, t_format *data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!data)
		return (0);
	while (i < 12)
	{
		if (SPECS[i] == data->specifier)
			len = g_dispatch[i](argp, data);
		i++;
	}
	return (len);
}

int		parse_format(va_list *argp, char *format, int *i)
{
	t_format	*data;
	char		*result;

	result = NULL;
	if (!(data = initialize_format()))
		return (0);
	*i += 1;
	set_data(data, format, i);
	if (data->specifier == '\0')
		return (clear_format(data));
	return (implement_data(argp, data));
}
