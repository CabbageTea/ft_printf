/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 00:20:00 by dglaser           #+#    #+#             */
/*   Updated: 2018/01/02 00:28:34 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_prewstrpad(int min, wchar_t *y, t_con *todo, int i)
{
	int x;

	x = 0;
	if (todo->minus_flag == 1)
	{
		while (y[i] != '\0' && i < todo->precision)
		{
			write(1, &y[i], 1);
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
			write(1, &y[i], 1);
			i++;
		}
	}
	return (x + i);
}

int		ft_wstr_output(t_con *todo, va_list ap, int i, int x)
{
	wchar_t	*y;

	y = va_arg(ap, wchar_t *);
	if (y == NULL)
		return (ft_nullstr(x));
	if (todo->min_width > 0 && todo->minus_flag == 0)
		x = ft_padding(todo->min_width - ft_wstrlen(y), *todo);
	if (todo->dot_flag == 1)
	{
		while (++i < todo->precision && y[i] != '\0')
		{
			write(1, &y[i], 1);
		}
	}
	else
	{
		while (y[++i] != '\0')
		{
			write(1, &y[i], 1);
		}
	}
	if (todo->min_width > 0 && todo->minus_flag == 1)
		x = ft_padding(todo->min_width - ft_wstrlen(y), *todo);
	return (x + ft_wstrlen(y));
}

int		ft_percisionwstring(t_con *todo, va_list ap, int i, int pad)
{
	wchar_t *y;

	y = va_arg(ap, wchar_t *);
	if ((int)ft_wstrlen(y) > todo->precision)
		pad = todo->precision;
	else
		pad = ft_wstrlen(y);
	if (todo->min_width > todo->precision)
	{
		i = i + ft_prewstrpad(todo->min_width - pad, y, todo, 0);
		return (i);
	}
	while (i < todo->precision && y[i] != '\0')
	{
		write(1, &y[i], 1);
		i++;
	}
	return (i);
}
