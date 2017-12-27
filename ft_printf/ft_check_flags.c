#include "ft_printf.h"

int	ft_isspecifier(char c);
int	ft_check_char(const char *format, int i, t_conditions *todo)
{
	while(format[i] != '\0' && format[i] != '%')
	{
		if(ft_isspecifier(format[i]))
		{
			todo->ch = format[i];
			return (1);
		}
		i++;
	}
	if (format[i] == '%')
	{
		todo->ch = '%';
		return (1);
	}
	return (0);
}

int	ft_width(int i, const char *format, t_conditions *todo)
{
	int temp;

	temp = 0;
	while (ft_isdigit(format[i])) 
	{
		temp = (temp * 10) + (format[i] - 48);
		todo->min_width = temp;
		i++;
	}
	return (i);
}

int		ft_precision(int i, const char *format, t_conditions *todo)
{
	char *temp;
	int z;

	z = 0;
	temp = (char *)malloc(sizeof(char) * 12);
	while(ft_isdigit(format[i]))
	{
		temp[z] = format[i];
		z++;
		i++;
	}
	temp[z] = '\0';
	todo->precision = ft_atoi(temp);
	todo->dot_flag = 1;
	free(temp);
	return (i);
}

int		ft_check_flags(const char *format, int i, t_conditions *todo)
{
	int x;
	x = 0;
	while (format[i] != '%' && (!ft_isspecifier(format[i])) && format[i] != '\0')
	{
		if (format[i] == '#')
			todo->hash_flag = 1;
		else if (ft_isdigit(format[i]))
		{
			if (format[i] == '0')
		   		todo->zero_flag = 1;
			else
				i = ft_width(i, format, todo) - 1;
		}
		else if (format[i] == '.')
			i = ft_precision(i + 1, format, todo);
		else if (format[i] == '-')
			todo->minus_flag = 1;
		else if (format[i] == '+')
		   todo->plus_flag = 1;
		else if (format[i] == ' ' && !ft_isspecifier(format[i - 1]))
		   todo->space_flag = 1;
		i++;
		x++;
	}
	return (x);
}






	


























