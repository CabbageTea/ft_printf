/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 21:06:15 by dglaser           #+#    #+#             */
/*   Updated: 2018/01/02 00:19:27 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <wchar.h>
# include <fcntl.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_conditions
{
	int				hash_flag;
	int				zero_flag;
	int				minus_flag;
	int				plus_flag;
	int				space_flag;
	int				min_width;
	int				dot_flag;
	int				precision;
	char			*temp;
	char			ch;
	int				neg;
	int				intlen;
	int				mod;
	int				star_flag;
	int				star_width;
	int				star_prec;

}					t_con;

void				ft_bzero(void *str, size_t n);
int					ft_printf(const char *format, ...);
int					ft_letter_output(va_list ap, t_con *todo);
int					ft_precision(int i, const char *format, t_con *todo);
int					ft_output(int i, va_list ap, t_con *todo);
int					ft_digits_output(va_list ap, t_con *todo, int len);
int					ft_isspecifier(char c);
char				*ft_un_base(uintmax_t num, int base);
int					ft_octal_output(uintmax_t num, t_con *todo, int len);
char				*ft_hex_base(uintmax_t num, int cap);
int					ft_point_output(uintmax_t num);
int					ft_hex(uintmax_t num, t_con *todo);
int					ft_unint_output(uintmax_t num, t_con *todo);
int					ft_ft_prestrpad(int min, char *y, t_con *todo);
int					ft_prezeropadding(uintmax_t num, t_con *todo);
int					ft_preminuspadding(uintmax_t num, t_con *todo);
int					ft_precisionpadding(t_con todo);
int					ft_padding(int min, t_con todo);
int					ft_nullstr(int i);
int					ft_prestrpad(int min, char *y, t_con *todo, int i);
int					ft_us_digits_output(va_list ap, t_con *todo);
int					ft_check_flags(const char *fo, int i, t_con *todo, int x);
int					ft_check_char(const char *format, int i, t_con *todo);
int					ft_isspecifier(char c);
int					ft_counttosp(const char *format, int i);
char				*ft_strrev(char *str);
int					ft_thissaves6lines(int len);
char				*ft_strnew(size_t size);
int					ft_percisionwstring(t_con *to, va_list ap, int i, int p);
int					ft_wstr_output(t_con *todo, va_list ap, int i, int x);

#endif
