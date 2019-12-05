/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:59:37 by asultanb          #+#    #+#             */
/*   Updated: 2019/12/04 17:50:10 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void	putnbr_ll(char specifier, unsigned long long n, int base)
{
	char	*hex;

	hex = (specifier == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	if (specifier == 'u' && n == 4294967295u)
	{
		ft_putstr("4294967295");
		return ;
	}
	if (n >= (unsigned long long)base)
		putnbr_ll(specifier, n / base, base);
	ft_putchar(hex[n % base]);
}

void	print_rem(int rem, char c)
{
	while (rem--)
		ft_putchar(c);
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

int		ft_fnumlen(long double f)
{
	int		len;
	int		rem;
	int		n;

	n = (int)f;
	len = (f < 0 || f == 0) ? 1 : 0;
	printf("%Lf\n%i\n", f, n);
	rem = f % n;
	printf("rem: %i\n", rem);
	while (f > 9)
	{
		f /= 10;
		len++;
	}
	/*
	if (f >= 1)
		len++;
	rem = f % 10;
	while (rem != 0)
	{
		rem /= 10;
		len++;
	}
*/

	return (len);

}
