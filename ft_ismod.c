#include "ft_printf.h"
int		ft_isspecifier(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'o'
			|| c == 'O' || c == 'u' || c == 'U' ||
		   	c == 'X' || c == 'x' || c == 'e' ||
		   	c == 'F' || c == 'f' || c == 'E' ||
		   	c == 'g' || c == 'G' || c == 'a' ||
		   	c == 'A' || c == 'c' || c == 'C' ||
		   	c == 's' || c == 'S' || c == 'p' || c == 'n')
		return (1);
	return (0);
}

int		ft_isflag (char c)
{
	if (c == '-' ||c == '+' ||c == ' ' ||c == '#' ||c == '0' || c == '.')
		return (1);
	return (0);
}

int		ft_istypespecifier(char c)
{
	if (c == 'h' ||c == 'l' ||c == 'j' ||c == 'z')
		return (1);
	return (0);
}

int		ft_counttosp(const char *format, int i)

{
	int x;
	x = 0;

	while (format[i] != '\0' && (!ft_isspecifier(format[i])) && format[i] != '%')
	{
		if (ft_isflag(format[i]) || ft_istypespecifier(format[i])
					|| ft_isdigit(format[i]) || format[i] == '%')
			x++;
		i++;
	}
	return (x + 1);

}

