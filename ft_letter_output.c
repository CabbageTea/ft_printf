/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 19:49:29 by dglaser           #+#    #+#             */
/*   Updated: 2018/01/02 00:24:30 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_nullstr(int i)
{
	ft_putstr("(null)");
	return (6 + i);
}

int			ft_char_output(t_con *todo, va_list ap)
{
	int		x;
	char	y;

	x = 0;
	if (todo->ch != '%')
		y = va_arg(ap, int);
	if (todo->ch == '%')
		y = '%';
	if (todo->min_width > 0 && todo->minus_flag == 0)
		x = ft_padding(todo->min_width - 1, *todo);
	write(1, &y, 1);
	if (todo->min_width > 0 && todo->minus_flag == 1)
		x = ft_padding(todo->min_width - 1, *todo);
	x++;
	return (x);
}

int			ft_str_output(t_con *todo, va_list ap)
{
	int		x;
	char	*y;
	int		i;

	x = 0;
	i = 0;
	y = va_arg(ap, char *);
	if (y == NULL)
		return (ft_nullstr(x));
	if (todo->min_width > 0 && todo->minus_flag == 0)
		x = ft_padding(todo->min_width - ft_strlen(y), *todo);
	if (todo->dot_flag == 1)
	{
		while (i < todo->precision && y[i] != '\0')
		{
			ft_putchar(y[i]);
			i++;
		}
	}
	else
		ft_putstr(y);
	if (todo->min_width > 0 && todo->minus_flag == 1)
		x = ft_padding(todo->min_width - ft_strlen(y), *todo);
	return (x + ft_strlen(y));
}

int			ft_percisionstring(t_con *todo, va_list ap)
{
	int		i;
	int		pad;
	char	*y;

	i = 0;
	y = va_arg(ap, char *);
	if ((int)ft_strlen(y) > todo->precision)
		pad = todo->precision;
	else
		pad = ft_strlen(y);
	if (todo->min_width > todo->precision)
	{
		i = i + ft_prestrpad(todo->min_width - pad, y, todo, 0);
		return (i);
	}
	while (i < todo->precision && y[i] != '\0')
	{
		ft_putchar(y[i]);
		i++;
	}
	return (i);
}

int			ft_letter_output(va_list ap, t_con *todo)
{
	int		x;

	x = 0;
	if (todo->ch == 'c' || todo->ch == 'C' || todo->ch == '%')
	{
		x = ft_char_output(todo, ap);
	}
	if (todo->dot_flag == 0)
	{
		if (todo->ch == 's' && todo->mod != 3)
			x = ft_str_output(todo, ap);
		if (todo->ch == 's' && todo->mod == 3)
			x = ft_wstr_output(todo, ap, -1, 0);
	}
	if (todo->dot_flag == 1)
	{
		if (todo->ch == 's' && todo->mod != 3)
			x = ft_percisionstring(todo, ap);
		if (todo->ch == 'S' && todo->mod == 3)
			x = ft_percisionwstring(todo, ap, 0, 0);
	}
	return (x);
}
