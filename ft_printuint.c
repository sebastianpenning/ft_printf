/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:45:03 by spenning          #+#    #+#             */
/*   Updated: 2023/12/18 21:13:36 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printunit(unsigned int arg)
{
	int	rtr;

	rtr = 0;
	if (arg == 0)
		rtr += ft_putchar_fd('0', 1);
	if (arg > 0)
	{
		if (arg > 9)
			rtr += printunit(arg / 10);
		rtr += ft_putchar_fd(48 + (arg % 10), 1);
	}
	return (rtr);
}

int	ft_printuint(va_list args)
{
	int				rtr;
	int				rtr_va_arg;
	unsigned int	arg;

	rtr = 0;
	rtr_va_arg = va_arg(args, int);
	arg = (unsigned int)rtr_va_arg;
	rtr = printunit(arg);
	return (rtr);
}
