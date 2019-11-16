/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:33:39 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/15 16:36:54 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

const t_dt	g_dt[] = 
{
	{'c', c_specifier},
	{'s', s_specifier},
	{'d', di_specifier},
	{'i', di_specifier},
	{'f', f_specifier},
	{'x', x_specifier},
	{'X', X_specifier},
	{'o', o_specifier},
	{'u', u_specifier},
	{'p', p_specifier},
	{'%', %_specifier},
	{0, NULL},
};


