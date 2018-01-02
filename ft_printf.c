/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 21:28:57 by dglaser           #+#    #+#             */
/*   Updated: 2018/01/01 23:57:28 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_mod(const char *fo, int i, t_con *todo)
{
	while (fo[i] != '%' && (!ft_isspecifier(fo[i])) && fo[i] != '\0')
	{
		if (fo[i] == 'h' && fo[i + 1] != 'h')
			todo->mod = 2;
		if (fo[i] == 'h' && fo[i + 1] == 'h')
		{
			todo->mod = 1;
			i++;
		}
		if (fo[i] == 'l' && fo[i + 1] != 'l')
			todo->mod = 3;
		if (fo[i + 1] == 'l' && fo[i] == 'l')
			todo->mod = 4;
		if (fo[i] == 'j')
			todo->mod = 5;
		if (fo[i] == 'z')
			todo->mod = 6;
		i++;
	}
	if ((todo->mod == 1) || (todo->mod == 4))
		return (2);
	if (todo->mod != 0)
		return (1);
	return (0);
}

int		ft_icfs(const char *format, int i, t_con *todo)
{
	int		y;
	int		x;

	x = 1;
	ft_check_flags(format, i + 1, todo, 0);
	y = ft_check_char(format, i + 1, todo);
	ft_check_mod(format, i + 1, todo);
	x = ft_counttosp(format, i + 1);
	if (y == 0)
	{
		ft_putstr("error");
		return (-1);
	}
	return (x + i);
}

int		ft_percent(int i, int *flag, size_t *num)
{
	write(1, "%", 1);
	*num = *num + 1;
	*flag = 1;
	return (i + 2);
}

int		ft_new(const char *fo, size_t num, t_con *todo, va_list ap)
{
	int				flag;
	static size_t	i;

	flag = 0;
	ft_bzero(todo, sizeof(t_con));
	while ((fo[i] != '\0') && (fo[i] != '%') && (i < ft_strlen(fo)))
	{
		write(1, &fo[i], 1);
		i++;
		num++;
	}
	if (fo[i] != '\0' && fo[i] == '%' && fo[i + 1] != '%' && (flag = 1))
	{
		if ((i = ft_icfs(fo, i, todo) + 1) == 0)
			return (0);
	}
	else if (fo[i] != '\0' && fo[i] == '%' && fo[i + 1] == '%')
		i = ft_percent(i, &flag, &num);
	if (flag == 1)
	{
		num = num + ft_output(0, ap, todo);
		num = ft_new(fo, num, todo, ap);
	}
	i = 0;
	return (num);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;
	t_con		todo;

	va_start(ap, format);
	ret = ft_new(format, 0, &todo, ap);
	va_end(ap);
	return (ret);
}
