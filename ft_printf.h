/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 23:03:23 by spenning      #+#    #+#                 */
/*   Updated: 2023/12/21 14:26:58 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// These are header guards that prevent the double definitions in the
// source file. This prevents library dependency from double copying
// libraries. if libft is already defined if won't define it again.
// name is LIBFT_H because the name should be the full filename of the
// header file, in all caps, with underscores for spaces and ​punctuation.

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//these inclusions are needed to be able to use the write function from
// unistd library. and va_list from the stdarg.h library. and the libft library

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

// This function prints out the format string + variables 
// depending on which format specifiers are given 
int		ft_printf(const char *format, ...);
// This function aids ft_printf by printing all variables
// which are passed with the %c formatter. The %c formatter is meant
// for characters
int		ft_printchar(va_list args);
// This function aids ft_printf by printing all variables
// which are passed with the %s formatter. The %s formatter is meant
// for string
int		ft_printstr(va_list args);
// This function aids ft_printf by printing all variables
// which are passed with the %i formatter. The %i formatter is meant
// for signed integers
int		ft_printint(va_list args);
// This function aids ft_printf by printing all variables
// which are passed with the %u formatter. The %u formatter is meant
// for unsigned integers
int		ft_printuint(va_list args);
// This function aids ft_printf by printing all variables
// which are passed with the %% formatter. The %% formatter is meant
// for ampersands
int		ft_printamp(void);
// This function aids the ft_printf by printing all variables
// which are passed with either the %x or %X formatter. 
// These formatters are used to print the hexidecimal values. 
// Which are then passed on to ft_hexconvert
int		ft_printhex(va_list args, char specifier);
// This function aids ft_printhex. the values and formatters are passed
// on to this function. This function recursively converts the value to 
// hexidecimal and then depending on the formatter will either print the 
// hexidecimal in upper or lowercase
int		ft_hexconvert(unsigned int arg, char specifier);
// This function aids ft_printf. by printing all variables
// which are passed with either the %p formatter.The %p formatter is meant
// for address of pointers. This function is similar to ft_printhex
int		ft_printptr(va_list args);
// This function aids ft_printptr. This function recursively converts the 
// value to hexidecimal and will then print the hexidecimal lowercase. This 
// function is similar such as ft_hexconvert
int		ft_hexconvertptr(long unsigned int arg);

#endif
