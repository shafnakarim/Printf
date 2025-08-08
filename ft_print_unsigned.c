/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srayees <srayees@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:47:30 by srayees           #+#    #+#             */
/*   Updated: 2025/08/08 15:37:34 by srayees          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int x)
{
	int	len;
	int	temp;

	len = 0;
	if (x < 10)
	{
		temp = write(1, &("0123456789"[x]), 1);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	else
	{
		temp = ft_print_unsigned(x / 10);
		if (temp == -1)
			return (-1);
		len += temp;
		temp = ft_print_unsigned(x % 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	return (len);
}
