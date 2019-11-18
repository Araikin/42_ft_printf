/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:44:49 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/17 17:03:20 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

t_fmt	*init_fmt(void)
{
	t_fmt	*data;

	if (!(data = malloc(sizeof(data))))
		return (NULL);
	data->specifier = '\0';
	data->precision = 0;
	data->width = 0;
	data->length = 0;
	data->flags = 0;
	return (data);
}
