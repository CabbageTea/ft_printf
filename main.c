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
	ft_printf("{%10d}", 42);
	ft_printf("{%-30S}", L"我是一只猫。");
	ft_printf("%5.5%");
	return (0);
}
