/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 19:41:32 by dglaser           #+#    #+#             */
/*   Updated: 2018/01/01 18:30:19 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		ft_dig_arg(va_list ap, t_con *todo)
{
	if (todo->mod == 1)
		return ((signed char)va_arg(ap, int));
	if (todo->mod == 2)
		return ((short)va_arg(ap, int));
	if (todo->mod == 3)
		return (va_arg(ap, long int));
	if (todo->mod == 4)
		return (va_arg(ap, long long));
	if (todo->mod == 5)
		return (va_arg(ap, intmax_t));
	if (todo->mod == 6)
		return (va_arg(ap, ssize_t));
	else
		return (va_arg(ap, int));
}

uintmax_t		ft_usdig_arg(va_list ap, t_con *todo)
{
	if (todo->mod == 1)
		return ((unsigned char)va_arg(ap, unsigned int));
	else if (todo->mod == 2)
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (todo->mod == 3)
		return (va_arg(ap, unsigned long int));
	else if (todo->mod == 4)
		return (va_arg(ap, unsigned long long int));
	else if (todo->mod == 5)
		return (va_arg(ap, uintmax_t));
	else if (todo->mod == 6)
		return (va_arg(ap, size_t));
	else
		return (va_arg(ap, unsigned int));
}

int				ft_dig_2(long long num, int len, t_con *todo)
{
	if (todo->minus_flag == 0 && todo->dot_flag == 1 &&
			todo->precision > todo->min_width
			&& todo->zero_flag && todo->space_flag == 0)
		return (ft_prezeropadding(num, todo));
	if (todo->minus_flag == 0 && todo->precision > ft_intlen(len)
			&& todo->space_flag)
		len = ft_thissaves6lines(len);
	if (todo->minus_flag == 0 && todo->precision > ft_intlen(len))
		len = ft_padding(todo->min_width - todo->precision, *todo);
	if (todo->minus_flag == 1 && todo->neg == 1)
		num = num * -1;
	if (todo->neg == 0 && todo->plus_flag == 0 &&
			todo->space_flag == 1 && todo->dot_flag == 0)
		len = ft_thissaves6lines(len);
	len = len + ft_intlen(num);
	if (num == 0 && todo->dot_flag == 1)
		return (len - 1);
	if (todo->plus_flag == 1 && todo->minus_flag == 1)
		ft_putchar('+');
	ft_putnbrmax(num);
	if (todo->minus_flag == 1 && todo->dot_flag == 0)
		len = len + ft_padding(todo->min_width - len, *todo);
	return (len);
}

int				ft_digits_output(va_list ap, t_con *todo, int len)
{
	long long	num;

	if (todo->ch == 'D')
		todo->mod = 3;
	num = ft_dig_arg(ap, todo);
	todo->intlen = ft_intlen(num);
	if (num < 0)
	{
		num = num * -1;
		todo->neg = 1;
	}
	if (todo->minus_flag == 0 && todo->min_width > 0 &&
			todo->space_flag == 1 && todo->precision == 0)
		todo->min_width--;
	if (todo->minus_flag == 1 && todo->dot_flag == 1)
		return (ft_preminuspadding(num, todo));
	if (todo->dot_flag == 1 && todo->min_width > todo->precision)
		return (ft_prezeropadding(num, todo));
	if (todo->plus_flag == 1 && todo->neg == 0 && todo->dot_flag == 1)
		todo->min_width--;
	if (todo->minus_flag == 0 && todo->precision <= ft_intlen(len) &&
			todo->dot_flag == 0)
		len = ft_padding(todo->min_width - (ft_intlen(num)), *todo);
	return (ft_dig_2(num, len, todo));
}

int				ft_us_digits_output(va_list ap, t_con *todo)
{
	uintmax_t	num;
	int			len;

	len = 0;
	if (todo->ch == 'U' || todo->ch == 'p' || todo->ch == 'O')
		todo->mod = 3;
	num = ft_usdig_arg(ap, todo);
	todo->plus_flag = 0;
	if (todo->ch == 'o' || todo->ch == 'O')
		len = ft_octal_output(num, todo, 0);
	if (todo->ch == 'x' || todo->ch == 'X')
		len = ft_hex(num, todo);
	if (todo->ch == 'u' || todo->ch == 'U')
		len = ft_unint_output(num, todo);
	if (todo->ch == 'p')
		len = ft_point_output(num);
	return (len);
}
