#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
//#include <limits.h>
#include <wchar.h>
#include <fcntl.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef struct		s_conditions
{
	int		hash_flag;
	int		zero_flag;
	int		minus_flag;
	int		plus_flag;
	int		space_flag;
	int		min_width;
	int		dot_flag;
	int		precision;
	char	*temp;
	char 	ch;
	int		neg;
	int		intlen;
	int		mod; // 1-6 hh,h,l,ll,j,z order

} t_con;



void		ft_bzero(void *str, size_t n);
int			ft_printf(const char *format, ...);
int			ft_letter_output(va_list ap, t_con *todo);
int			ft_precision(int i, const char *format, t_con *todo);
int			ft_output(int i, va_list ap, t_con *todo);
int			ft_digits_output(va_list ap, t_con *todo);
int			ft_isspecifier(char c);
char		*ft_un_base(uintmax_t num, int base);
int			ft_octal_output(uintmax_t num, t_con *todo);
char		*ft_hex_base(uintmax_t num, int cap);
int			ft_hex(uintmax_t num, t_con *todo);
int			ft_unint_output(uintmax_t num, t_con *todo);
int			ft_ft_prestrpad(int min, char *y, t_con *todo);
#endif

