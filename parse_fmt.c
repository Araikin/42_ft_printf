/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:48:55 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/15 13:49:00 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		is_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'd' ||
			c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' ||
			c == 'f');
}

void	set_specifier(char *fmt, int *i, t_fmt *data)
{
	
}

void	parse_fmt(char *fmt, int *i, t_fmt *data)
{
	*i += 1;

	if (fmt[*i])
	{
		if (is_specifier(fmt[*i]))	
			set_specifier(fmt, i, data);
	}

}

void	proc_fmt(va_list *argp, char *fmt, int *i, int *num)
{
	t_fmt	*data;
	
	if (!(data = init_fmt()))	
		return ;
	parse_fmt(fmt, i, data);
}
