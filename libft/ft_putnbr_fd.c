/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:34:43 by spenning          #+#    #+#             */
/*   Updated: 2023/12/18 21:24:11 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int d, int fd)
{
	int			rtr;
	long int	ld;

	ld = (long int)d;
	rtr = 0;
	if (ld < 0)
	{
		rtr += ft_putchar_fd('-', fd);
		ld *= -1;
	}
	if (ld == 0)
		rtr += ft_putchar_fd('0', fd);
	if (ld > 0)
	{
		if (ld > 9)
		{
			rtr += ft_putnbr_fd(ld / 10, fd);
		}
		rtr += ft_putchar_fd(48 + (ld % 10), fd);
	}
	return (rtr);
}
