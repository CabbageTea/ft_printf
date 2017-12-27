
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
int		ft_check_flags(const char *format, int i, t_conditions *todo);
int		ft_check_char(const char *format, int i, t_conditions *todo);
int		ft_isspecifier(char c);
int		ft_counttosp(const char *format, int i);

int		ft_check_mod(const char *format, int i, t_conditions *todo)
{
	while (format[i] != '%' && (!ft_isspecifier(format[i])) && format[i] != '\0')
	{
		if (format[i] == 'h')
		{
			if (format[i + 1] == 'h')
			{
				todo->mod = 1;
				return (2);
			}
			todo->mod = 2;
			return (1);
		}
		if (format[i] == 'l')
		{
			if (format[i + 1] == 'l')
			{
				todo->mod = 4;
				return (2);
			}
			todo->mod = 3;
			return (1);
		}
		if (format[i] == 'j')
		{
			todo->mod = 5;
			return (1);
		}
		if (format[i] == 'z')
		{
			todo->mod = 6;
			return (1);
		}
		i++;
	}
	return (0);
}
		
int		ft_icfs(const char *format, int i, t_conditions *todo)
{
	int y;
	int x = 1;
	ft_check_flags(format, i + 1, todo); //returns 1 for succesful flag/con sets 
	y = ft_check_char(format, i + 1, todo);
	ft_check_mod(format, i + 1, todo);
	x = ft_counttosp(format, i + 1);
	if (y == 0)
		exit(0);
	return (x); 
}	

int 		ft_percent(int i)
{
	write(1, "%", 1);
	return (i + 2);
}

int			ft_newpercent(const char *format, size_t i, size_t num, t_conditions *todo, va_list ap)
{
	int flag; 
	flag = 0;
	ft_bzero(todo, sizeof(t_conditions));

		while  ((format[i] != '\0') && (format[i] != '%') && (i < ft_strlen(format)))
		{
			write(1, &format[i], 1);
			i++;
			num++;
		}
		if (format[i] != '\0' && format[i] == '%' && format[i + 1] != '%')
		{
			i = i +  ft_icfs(format, i, todo) + 1; //invalid checker flag setter
			flag = 1;
		}
		else if (format[i] != '\0' && format[i] == '%' && format[i + 1] == '%')
		{
			flag = 1;
			i = ft_percent(i); //% has to do flags 
			num++;
		}

	if (flag == 1)
	{
		num = num + ft_output(0, ap, todo);
		num = ft_newpercent(format, i, num, todo, ap);
	}
	return (num);
}
	
int			ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int ret;
	t_conditions todo;
	ret = ft_newpercent(format, 0 , 0, &todo, ap); 
	va_end(ap);
	return (ret);
}

/*int main(void)
{	
	ft_printf("%-05d", -42);
--	return (0);
}*/
