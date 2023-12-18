/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printamp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/03 10:44:00 by spenning      #+#    #+#                 */
/*   Updated: 2023/12/03 10:44:02 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printamp(void)
{
	int	rtr;

	rtr = 0;
	rtr += ft_putchar_fd('%', 1);
	return (rtr);
}
