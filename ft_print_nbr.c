/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srayees <srayees@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:25:09 by srayees           #+#    #+#             */
/*   Updated: 2025/08/08 16:09:54 by srayees          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	long	num;
	char	digit;
	int		len;
	int		temp;

	len = 0;
	num = n;
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		num = -num;
	}
	if (num >= 10)
	{
		temp = ft_print_nbr(num / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	digit = '0' + (num % 10);
	if (write(1, &digit, 1) == -1)
		return (-1);
	return (len + 1);
}
