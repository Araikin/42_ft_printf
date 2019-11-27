/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:01:21 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/26 16:20:01 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	adjust_width_c(t_format *data, int c)
{
	int		width_rem;
	char	flag;

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
}

int		adjust_width(t_format *data, char *str)
{
	int		width_rem;
	int		len;
	char	flag;
	int		i;
	int		count;

	str = (str == NULL) ? "(null)" : str;
	len = (int)ft_strlen(str);
	flag = (data->flags & ZERO && !(data->flags & MINUS)) ? '0' : ' ';
	len = (data->precision == 0) ? len : (ft_min(data->precision, len));
	len = (data->precision == -1) ? 0 : len;
	width_rem = data->width - len; 
	width_rem = (width_rem < 0) ? 0 : width_rem;
	i = 0;
	if (data->flags & MINUS)
		while (len-- && str[i])
			ft_putchar(str[i++]);
	count = len + width_rem;
	while (width_rem--)
		ft_putchar(flag);
	if (len > 0 && (!(data->flags) || !(data->flags & MINUS)))
		while (len-- && str[i])
			ft_putchar(str[i++]);
	return (count);
}
