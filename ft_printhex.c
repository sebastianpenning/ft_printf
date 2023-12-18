/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:06:04 by mynodeus          #+#    #+#             */
/*   Updated: 2023/12/18 21:06:33 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(va_list args, char specifier)
{
	int				rtr;
	unsigned int	arg;

	rtr = 0;
	arg = va_arg(args, unsigned int);
	if (arg == 0)
	{
		rtr += ft_putchar_fd('0', 1);
		return (rtr);
	}
	rtr += ft_hexconvert(arg, specifier);
	return (rtr);
}
