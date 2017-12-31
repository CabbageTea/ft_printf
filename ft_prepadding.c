/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepadding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 20:03:33 by dglaser           #+#    #+#             */
/*   Updated: 2017/12/30 19:48:04 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			preminpt2(uintmax_t num, int i, int zeros, t_con *todo)
{
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

int			ft_preminuspadding(uintmax_t num, t_con *todo)
{
	int		i;
	int		zeros;

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
	return (preminpt2(num, i, zeros, todo));
}

int			prezeropt2(uintmax_t num, int i, t_con *todo)
{
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

int			ft_prezeropadding(uintmax_t num, t_con *todo)
{
	int		min;
	int		i;

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
	return (prezeropt2(num, i, todo));
}
