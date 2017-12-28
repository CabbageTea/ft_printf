#include "ft_printf.h"
int		ft_us_digits_output(va_list ap, t_con *todo);

int	ft_precisionpadding(t_con todo)
{
	int i;
	int x;
	x = 0;
	if (todo.intlen != 0)
	{
		i = todo.intlen;
		if (todo.neg == 1)
			i--;
		while (i < todo.precision)
		{
			ft_putnbr(0);
			i++;
			x++;
		}
	}
	return (x);
}

int		ft_output(int i, va_list ap, t_con *todo)
{
		if (todo->ch == 'c' || todo->ch == 'C' || todo->ch == 's' || todo->ch == 'S' || todo->ch == '%')
			i = i + ft_letter_output(ap, todo);
	if ((todo->ch == 'd') || (todo->ch == 'D') || (todo->ch == 'i'))
		i = i + ft_digits_output(ap, todo);
	if ((todo->ch == 'o') || (todo->ch == 'O') || 
				(todo->ch == 'u') || (todo->ch == 'U') ||
				(todo->ch == 'x') || (todo->ch == 'X') ||
				(todo->ch == 'p'))
			i = i + ft_us_digits_output(ap, todo);
		return (i);
}
	

int		ft_zpadding(int min, t_con todo)
{
	int i;
	i = 0;
	if (todo.neg == 1)
	{
		write(1, "-", 1);
		i++;
	}
	if (todo.plus_flag == 1 && todo.neg == 0)
	{
		write(1, "+", 1);
		i++;
	}
	if (todo.ch == 'x' && todo.hash_flag == 1)
		ft_putstr("0x");
	if (todo.ch == 'X' && todo.hash_flag == 1)
		ft_putstr("0X");
	while (i < min)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}
int		ft_padding(int min, t_con todo)
{
	int i;
	int x;
	x = 0;
	i = 0;
	if (todo.zero_flag == 1 && todo.minus_flag == 0)
		return (ft_zpadding(min, todo));
	if (todo.neg == 1 && todo.minus_flag == 0)
		min--;
	while (i < min)
	{
		write(1, " ", 1);
		i++;
	}
	if (todo.neg == 1 && todo.minus_flag == 0)
	{
		write(1, "-", 1);
		i++;
	}
	if (todo.neg == 0 && todo.minus_flag == 0 && todo.plus_flag == 1)
	{
		write( 1, "+", 1);
		i++;
	}
	i = i + ft_precisionpadding(todo);
	return (i);
}

int		ft_preminuspadding(uintmax_t num, t_con *todo)
{
	int i;
	int zeros;

	zeros = todo->precision - ft_intlen(num);
	i = 0;
	if (todo->plus_flag == 1) 
	{
		write(1, "+", 1);
		i++;
	}
	if (todo->neg == 1)
	{
		write(1, "-", 1);
		i++;
	}
	if (ft_intlen(num) < todo->precision)
	{
		while (zeros > 0)
		{
			write(1, "0", 1);
			zeros--;
			i++;
		}
	}
		ft_putnbr(num);
	i = i + ft_intlen(num);
	while (todo->min_width > i)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}
int		ft_prezeropadding(uintmax_t num, t_con *todo)
{
	int min;
	int i;

	i = 0;
	if (todo->precision > ft_intlen(num))
		min = todo->min_width - todo->precision;
	else 
		min = todo->min_width - ft_intlen(num);
	if (todo->plus_flag == 1 || todo->neg == 1)
		min--;
	while (min > 0)
	{
		ft_putchar(' ');
		min--;
		i++;
	}
	if (todo->plus_flag == 1)
	{
		i++;
		ft_putchar('+');
	}
	if (todo->neg == 1)
	{
		i++;
		ft_putchar('-');
	}
	while (todo->precision > ft_intlen(num))
	{
		ft_putchar('0');
		todo->precision--;
	}
	i = i + ft_intlen(num);
	if (num == 0 && todo->precision == 0)
	{
		ft_putchar(' ');
		i--;
	}
	else
		ft_putnbr(num);
	return (i + 1);
}
