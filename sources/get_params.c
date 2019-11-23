#include "../includes/ft_printf.h"

void	get_width(char *params, t_format *data)
{
	
}

void	get_specifier(char *params, t_format *data)
{
	int	pos = 0;
	while (params[pos] && !is_specifier(params[pos]))
		pos++;
	if (is_specifier(params[pos]))
		data->specifier = params[pos];
}


