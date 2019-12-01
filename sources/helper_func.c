/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:59:37 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/30 14:36:36 by asultanb         ###   ########.fr       */
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

int		ft_numlen(unsigned long long n, int base)
{
	int	len;

	len = 0;
	len = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		n /= base;
		len++;		
	}
	return (len);
}

int		ft_numlen_int(int n, int base)
{
	int len;

	len = 0;
	len = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*itoa_base(unsigned long long n, int base, char c)
{
	char	*hex; 
	char	*str;
	int		i;
	int		len;

	str = NULL;
	len = ft_numlen(n, base);
	hex = (c == 'u') ? "0123456789ABCDEF" : "0123456789abcdef";
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (n != 0)
	{
		str[--len] = hex[n % base];
		n /= base;
	}
	return (str);
}
void	print_rem(int rem, char c)
{
	while (rem--)
		ft_putchar(c);
}
