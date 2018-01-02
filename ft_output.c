/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 20:03:33 by dglaser           #+#    #+#             */
/*   Updated: 2018/01/01 17:14:31 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_precisionpadding(t_con todo)
{
	int		i;
	int		x;

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

int			ft_thissaves6lines(int len)
{
	len++;
	ft_putchar(' ');
	return (len);
}

int			ft_output(int i, va_list ap, t_con *todo)
{
	if (todo->star_width == 1)
		todo->min_width = (va_arg(ap, int));
	if (todo->star_prec == 1)
		todo->precision = (va_arg(ap, int));
	if (todo->ch == 'c' || todo->ch == 'C' ||
		todo->ch == 's' || todo->ch == 'S' || todo->ch == '%')
		i = i + ft_letter_output(ap, todo);
	if ((todo->ch == 'd') || (todo->ch == 'D') || (todo->ch == 'i'))
		i = i + ft_digits_output(ap, todo, 0);
	if ((todo->ch == 'o') || (todo->ch == 'O') ||
		(todo->ch == 'u') || (todo->ch == 'U') ||
		(todo->ch == 'x') || (todo->ch == 'X') ||
		(todo->ch == 'p'))
		i = i + ft_us_digits_output(ap, todo);
	return (i);
}

int			ft_zpadding(int min, t_con todo)
{
	int		i;

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

int			ft_padding(int min, t_con todo)
{
	int		i;
	int		x;

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
		write(1, "+", 1);
		i++;
	}
	return (i + ft_precisionpadding(todo));
}
