/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:06:06 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/17 17:28:38 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_printf(const char *fmt, ...)
{
	int		i;
	int		num;
	va_list	argp;
	
	va_start(argp, fmt);
	i = 0;
	num = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
			proc_fmt(&argp, (char*)fmt, &i, &num);
		else
		{
			ft_putchar(fmt[i++]);
			num++;
		}
	}
	va_end(argp);
	return (num);
}
