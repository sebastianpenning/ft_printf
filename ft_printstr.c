/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:44:57 by spenning          #+#    #+#             */
/*   Updated: 2023/12/18 21:10:22 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(va_list args)
{
	int		rtr;
	char	*str;

	str = va_arg(args, char *);
	rtr = 0;
	if (str == NULL)
		rtr = ft_putstr_fd("(null)", 1);
	else
	{
		while (*str)
		{
			rtr += ft_putchar_fd(str[0], 1);
			str++;
		}
	}
	return (rtr);
}
