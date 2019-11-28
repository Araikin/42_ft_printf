/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 13:32:55 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/27 18:35:51 by asultanb         ###   ########.fr       */
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
	int		width_rem;
	int		len;
	char	flag;
	int		count;

	str = va_arg(*argp, char *);
	str = (str == NULL) ? "(null)" : str;
	len = (int)ft_strlen(str);
	flag = (data->flags & ZERO && !(data->flags & MINUS)) ? '0' : ' ';
	len = (data->prec == 0) ? len : (ft_min(data->prec, len));
	len = (data->prec == -1) ? 0 : len;
	width_rem = (data->width - len < 0) ? 0 : (data->width - len); 
	count = len + width_rem;
	if (data->flags & MINUS)
		while (len-- && *str)
			ft_putchar(*str++);
	while (width_rem--)
		ft_putchar(flag);
	if (len > 0 && (!(data->flags) || !(data->flags & MINUS)))
		while (len-- && *str)
			ft_putchar(*str++);
	return (count);
}

int		p_specifier(va_list *argp, t_format *data)
{
	void	*ptr;
	char	*str;
	int		w_rem;
	int		p_rem;
	int		len;

	ptr = va_arg(*argp, void *);
	str = itoa_base((unsigned long long)ptr, 16, 'l');
	len = update_rem(&p_rem, &w_rem, str, data);
	(data->flags & MINUS) ? (ft_putstr("0x")) : (ft_putstr(""));
	(data->flags & MINUS) ? (print_rem(p_rem, '0')) : ft_putstr("");
	(data->flags & MINUS) ? (ft_putstr(str)) : ft_putstr("");
	(data->flags & MINUS) ? print_rem(w_rem, ' ') : ft_putstr("");
	if ((data->flags && !(data->flags & MINUS)) || !data->flags)
	{
		if (data->prec || (!data->prec && !(data->flags & ZERO)))
		{
			print_rem(w_rem, ' ');
			ft_putstr("0x");
			print_rem(p_rem, '0');
			ft_putstr(str);
		}
		else if (!data->prec && (data->flags & ZERO)) 
		{
			ft_putstr("0x");
			print_rem(w_rem, '0');
			ft_putstr(str);
		}
	}
	return(len);
}

/*
int		d_specifier(va_list *argp, t_format *data)
{
	int		n;

	n = va_arg(*argp, void *);

}
*/
