/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:14:01 by asultanb          #+#    #+#             */
/*   Updated: 2019/12/06 17:48:36 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <float.h>

int		main(void)
{

	printf("%.2000f\n", DBL_MIN);
	ft_printf("%.2000f\n", DBL_MIN);
	//printf("o: %#.0f\n", -3.9999999);
	//ft_printf("m: %#.0f\n", -3.9999999);
	//printf("%i\n", printf("%f\n%lf\n%Lf\n", 1.42, 1.42, 1.42l));
	//printf("%i\n", ft_printf("%f\n%lf\n%Lf\n", 1.42, 1.42, 1.42l));

	return (0);
}
