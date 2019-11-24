/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 13:20:44 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/23 15:08:57 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'o' || c == 'u' ||
			c == 'x' || c == 'X' || c == 'd' || c == 'D' || c == 'i' ||
			c == 'f' || c == '%');
}

int		is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#');
}

int		is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
