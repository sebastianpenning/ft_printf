/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:44:37 by spenning          #+#    #+#             */
/*   Updated: 2023/12/18 21:08:03 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(va_list args)
{
	int	arg;
	int	rtr;

	arg = va_arg(args, int);
	rtr = 0;
	rtr = ft_putnbr_fd(arg, 1);
	return (rtr);
}
