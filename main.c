#include "ft_printf.h"
int main(void)
/*{
	char *s1 = "Hello world";
	char *s2 = "cats are cool";

	ft_printf("%s yo %% I can't type %d, %+i, %06.3d, %#5.5X", s1, 23, 573443, 89, 567);
	ft_printf("%s", s2);

	while (1);
	return (0);
}*/
{
	// test->debug = 1;
	ft_printf("*.5i 42 == |% *.5i|\n", 4, 42);
	ft_printf("%%*i 42 == |%*i|\n", 5, 42);
	ft_printf("%%*i 42 == |%*i|\n", 3, 42);
	ft_printf("%%*i 42 == |%kokokoki|\n", 2, 42);
	ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	ft_printf("%%*i 42 == |%*i|\n", 5, 42);
	ft_printf("%%*i 42 == |%*i|\n", 3, 42);
	ft_printf("%%*i 42 == |%*i|\n", 2, 42);
}
