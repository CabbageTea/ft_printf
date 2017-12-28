
#include "ft_printf.h"

int		ft_prestrpad(int min, char *y, t_con *todo)
{
	int i;
	int x;

	x = 0;
	i = 0;
	if (todo->minus_flag == 1)
	{
		while (y[i] != '\0' && i < todo->precision)
		{
			ft_putchar(y[i]);
			i++;
		}
	}
	while (x < min)
	{
		ft_putchar(' ');
		x++;
	}
	if (todo->minus_flag == 0)
	{
		while (y[i] != '\0' && i < todo->precision)
		{
			ft_putchar(y[i]);
			i++;
		}
	}
	return (x + i);
}
