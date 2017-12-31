/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 17:49:16 by dglaser           #+#    #+#             */
/*   Updated: 2017/12/30 21:13:50 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			un_base_len(uintmax_t num, int base)
{
	int		o;

	o = 0;
	while (num > 0)
	{
		num = num / base;
		o++;
	}
	return (o);
}

char		*ft_hex_base(uintmax_t num, int cap)
{
	char	*ret;
	int		x;
	int		i;

	i = 0;
	x = 0;
	ret = (char *)malloc(sizeof(char) * 60);
	if (num == 0)
		ret[i++] = x + 48;
	while (num > 0)
	{
		x = num % 16;
		num = num / 16;
		if (x < 10)
			ret[i] = x + 48;
		else if (cap == 1)
			ret[i] = x + 55;
		else if (cap == 0)
			ret[i] = x + 87;
		i++;
	}
	ret[i] = '\0';
	ret = ft_strrev(ret);
	return (ret);
}

char		*ft_strrev(char *str)
{
	int		i;
	int		x;
	char	*ret;

	x = 0;
	i = ft_strlen(str) - 1;
	ret = ft_strnew(i + 1);
	while (i >= 0)
	{
		ret[x] = str[i];
		i--;
		x++;
	}
	ret[x] = '\0';
	free(str);
	return (ret);
}

char		*ft_un_base(uintmax_t num, int base)
{
	int		len;
	char	*ret;

	len = un_base_len(num, base);
	ret = (char *)malloc(sizeof(char) * len + 1);
	ret[len] = '\0';
	len--;
	while (num > 0)
	{
		ret[len] = (num % base) + 48;
		num = num / base;
		len--;
	}
	return (ret);
}
