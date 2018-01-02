/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 20:49:56 by dglaser           #+#    #+#             */
/*   Updated: 2018/01/01 19:06:48 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_octal_output(uintmax_t num, t_con *todo, int len)
{
	char	*oct;
	int		buf;

	oct = ft_un_base(num, 8);
	len = ft_strlen(oct);
	if (todo->hash_flag == 1)
		len++;
	buf = todo->precision - len;
	buf > 0 ? len = len + buf : 0;
	if (todo->minus_flag == 0)
		len = len + ft_padding(todo->min_width - len, *todo);
	if (todo->hash_flag == 1)
		ft_putnbr(0);
	while (buf-- > 0)
		ft_putnbr(0);
	if (num == 0 && todo->hash_flag == 0 && todo->dot_flag == 0)
	{
		ft_putnbr(0);
		len++;
	}
	ft_putstr(oct);
	free(oct);
	if (todo->minus_flag == 1)
		len = len + ft_padding(todo->min_width - len, *todo);
	return (len);
}

int		ft_hex(uintmax_t num, t_con *todo)
{
	char	*hex;
	int		len;

	if (num == 0 && todo->dot_flag == 1 && todo->min_width == 0)
		return (0);
	hex = ft_hex_base(num, (todo->ch == 'x' ? 0 : 1));
	len = ft_strlen(hex);
	todo->hash_flag && num != 0 ? len = len + 2 : len;
	if (todo->minus_flag == 0)
		len = len + ft_padding(todo->min_width - len, *todo);
	if (todo->zero_flag == 0 || todo->minus_flag)
	{
		if (todo->ch == 'x' && todo->hash_flag == 1 && num != 0)
			ft_putstr("0x");
		if (todo->ch == 'X' && todo->hash_flag == 1 && num != 0)
			ft_putstr("0X");
	}
	if (num == 0 && todo->dot_flag == 1)
		ft_putchar(' ');
	else
		ft_putstr(hex);
	if (todo->minus_flag == 1)
		len = len + ft_padding(todo->min_width - len, *todo);
	free(hex);
	return (len);
}

int		ft_point_output(uintmax_t num)
{
	char		*ret;
	int			len;
	uintmax_t	*p;

	p = &num;
	ret = ft_hex_base(*p, 0);
	len = ft_strlen(ret);
	len = len + 2;
	ft_putstr("0x");
	ft_putstr(ret);
	free(ret);
	return (len);
}

int		ft_unint_output(uintmax_t num, t_con *todo)
{
	int len;

	len = ft_unintlen(num);
	if (todo->minus_flag == 0)
		len = len + ft_padding(todo->min_width - ft_intlen(num), *todo);
	if (todo->minus_flag == 0 && todo->dot_flag == 1)
	{
		while (len < todo->precision)
		{
			ft_putchar('0');
			len++;
		}
	}
	ft_putnbrunmax(num);
	if (todo->minus_flag == 1)
		len = len + ft_padding(todo->min_width - ft_intlen(num), *todo);
	return (len);
}
