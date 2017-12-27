#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int 	un_base_len(uintmax_t num,  int base)
{
	int o;
	o = 0;
	while (num > 0)
	{
		num = num/base;
		o++;
	}
	return (o);
}


char *ft_base(uintmax_t num, int base)
{
	int len;
	char *ret;
	len = un_base_len(num, base);
	ret = strnew(len + 1);
	while (num > 0)
	{
		ret[len] = num % base;
		num = num / base;
		len--;
	}
	return (ret);
}

int	main(void)

{
	int i = 99;

	char *x =  ft_base(i, 8);	
	printf("%s", x);

	return (0);

}
