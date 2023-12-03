
#include "ft_printf.h"

int	ft_printhex(va_list args, char specifier)
{
	int rtr;
	unsigned int arg;
	
	rtr = 0;
	arg = va_arg(args, unsigned int);
	if(arg == 0)
	{
		rtr += ft_putchar_fd('0', 1);
		return (rtr);
	}
	rtr += ft_hexconvert(arg, specifier);
	return (rtr);
}