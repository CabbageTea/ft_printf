/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 17:59:15 by dglaser           #+#    #+#             */
/*   Updated: 2018/01/01 18:12:00 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_char(const char *format, int i, t_con *todo)
{
	while (format[i] != '\0' && format[i] != '%')
	{
		if (ft_isspecifier(format[i]))
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

void	ft_star_flag(t_con *todo, int i, const char *fo)
{
	todo->star_flag = 1;
	if (fo[i - 1] == '.')
		todo->star_prec = 1;
	else
		todo->star_width = 1;
}

int		ft_width(int i, const char *format, t_con *todo)
{
	int	temp;

	temp = 0;
	while (ft_isdigit(format[i]))
	{
		temp = (temp * 10) + (format[i] - 48);
		todo->min_width = temp;
		i++;
	}
	return (i);
}

int		ft_precision(int i, const char *format, t_con *todo)
{
	char	*temp;
	int		z;

	z = 0;
	temp = (char *)malloc(sizeof(char) * 12);
	while (ft_isdigit(format[i]))
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

int		ft_check_flags(const char *fo, int i, t_con *todo, int x)
{
	while (fo[i] != '%' && (!ft_isspecifier(fo[i])) && fo[i] != '\0')
	{
		if (fo[i] == '#')
			todo->hash_flag = 1;
		else if (ft_isdigit(fo[i]))
		{
			if (fo[i] == '0')
				todo->zero_flag = 1;
			else
				i = ft_width(i, fo, todo) - 1;
		}
		else if (fo[i] == '.')
			i = ft_precision(i + 1, fo, todo);
		else if (fo[i] == '-')
			todo->minus_flag = 1;
		else if (fo[i] == '+')
			todo->plus_flag = 1;
		else if (fo[i] == ' ' && !ft_isspecifier(fo[i - 1]))
			todo->space_flag = 1;
		else if (fo[i] == '*')
			ft_star_flag(todo, i, fo);
		i++;
		x++;
	}
	return (x);
}
