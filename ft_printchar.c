/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printchar.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/03 10:44:06 by spenning      #+#    #+#                 */
/*   Updated: 2023/12/03 10:44:12 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(va_list args)
{
	int	c;

	c = va_arg(args, int);
	c = (char)c;
	write(1, &c, 1);
	return (1);
}
