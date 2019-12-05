/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:09:14 by asultanb          #+#    #+#             */
/*   Updated: 2019/12/04 17:17:37 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
