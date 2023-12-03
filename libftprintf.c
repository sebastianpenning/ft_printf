/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/03 10:45:10 by spenning      #+#    #+#                 */
/*   Updated: 2023/12/03 12:41:05 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int check_datatype (const char specifier, va_list args)
{
	int rtr;

	rtr = 0;
	if(specifier == 'c')
		rtr = ft_printchar(args);
	if(specifier == 's')
		rtr = ft_printstr(args);
	if(specifier == 'd')
		rtr = ft_printint(args);
	if(specifier == 'i')
		rtr = ft_printint(args);
	if(specifier == 'u')
		rtr = ft_printuint(args);
	if(specifier == '%')
		rtr = ft_printamp();
	if(specifier == 'x' || specifier == 'X')
		rtr = ft_printhex(args, specifier);
	if(specifier == 'p')
		rtr = ft_printptr(args);
	return (rtr);
}

int ft_printf(const char *format, ...)
{
	int rtr;
	va_list args;

	rtr = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			rtr += check_datatype(format[1], args);
			format += 2;
		}
		else
		{
			rtr += ft_putchar_fd(format[0], 1);
			format++;
		}
	}
	va_end(args);
	return(rtr);
}
