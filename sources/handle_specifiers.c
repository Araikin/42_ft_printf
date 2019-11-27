/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 13:32:55 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/26 16:41:04 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		c_specifier(va_list *argp, t_format *data)
{
	int		c;
	int		width_rem;
	char	flag;

	c = va_arg(*argp, int);
	flag = (data->flags & ZERO && !(data->flags & MINUS)) ? '0' : ' ';
	if (data->width < 1)
		data->width = 1;
	width_rem = data->width - 1;
	if (data->flags & MINUS)
		ft_putchar(c);
	while (width_rem--)
		ft_putchar(flag);
	if (data->width > 0 && (!(data->flags) || !(data->flags & MINUS)))
		ft_putchar(c);
	return (data->width);
}

int		s_specifier(va_list *argp, t_format *data)
{
	char 	*str;

	str = va_arg(*argp, char *);
	return(adjust_width(data, str));
}

int		p_specifier(va_list *argp, t_format *data)
{
	void	*ptr;
	char	*str;

	ptr = va_arg(*argp, void *);
	str = adjust_precision(itoa_base((unsigned long long)ptr, 16, 'l'));
	str = ft_strjoin("0x", str);
	return(adjust_width(data, str));
}
