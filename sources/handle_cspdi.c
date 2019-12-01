/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cspdi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:32:05 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/30 18:05:56 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		handle_c(va_list *argp, t_format *data)
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

int		handle_s(va_list *argp, t_format *data)
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

void	adjust_p(t_format *data, int p_rem, int w_rem, char *str)
{
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
}

int		handle_p(va_list *argp, t_format *data)
{
	void	*ptr;
	char	*str;
	int		w_rem;
	int		p_rem;
	int		len;

	ptr = va_arg(*argp, void *);
	str = itoa_base((unsigned long long)ptr, 16, 'l');
	if (str[0] == '0' && str[1] == '\0' && data->prec == -1)
	{
		ft_putstr("0x");
		return (2);
	}
	len = (int)ft_strlen(str);
	if (data->prec > len)
		p_rem = data->prec - len;
	else
		p_rem = 0;
	if (len + p_rem + 2 > data->width)
		w_rem = 0;
	else
		w_rem = data->width - len - p_rem - 2;
	len = len + 2 + p_rem + w_rem;
	adjust_p(data, p_rem, w_rem, str);
	return(len);
}

int		adjust_di(t_format *data, int64_t n)
{
	int		len;
	int		p_rem;
	int		w_rem;
	char	flag;

	p_rem = 0;
	w_rem = 0;
	flag = ' ';
	len = ft_numlen((unsigned long long)n, 10);
	if (n < 0)
		len = ft_numlen((unsigned long long)(n * -1), 10);
	if (data->flags & ZERO && !(data->flags & MINUS) && !data->prec)
		flag = '0';
	if (data->prec > len)
		p_rem = data->prec - len;
	if (data->width > ft_max(data->prec, len))
		w_rem = data->width - ft_max(data->prec, len) - ((n < 0) ? 1 : 0);


	(data->prec && n < 0) ? ft_putchar('-') : ft_putstr("");

	!(data->flags & MINUS) ? print_rem(w_rem, flag) : print_rem(p_rem, '0');
	!(data->flags & MINUS) ? print_rem(p_rem, '0') : ft_putnbr(n * -1);
	!(data->flags & MINUS) ? ft_putnbr(n * -1) : print_rem(w_rem, flag);
	return (0);
	
}

int		handle_di(va_list *argp, t_format *data)
{
	int64_t n;

	if (data->length & L)
		n = va_arg(argp, long int);
	else if (data->length & LL)
		n = va_arg(argp, long long int);
	else if (data->length & H)
		n = (short int)va_arg(argp, int);
	else if (data->length & HH)
		n = (signed char)va_arg(argp, int);
	else
		n = va_arg(argp, int);
	return (adjust_di(data, n));
}
