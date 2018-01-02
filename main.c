#include "ft_printf.h"

int main(void)
{
	wchar_t wz [3] = L"@@";
	ft_printf("%S", wz);
	printf("\nthis is real -> %S", wz);
	return (0);
}

