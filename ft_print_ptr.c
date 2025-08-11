/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srayees <srayees@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:24:44 by srayees           #+#    #+#             */
/*   Updated: 2025/08/11 12:11:33 by srayees          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_hex_address(unsigned long long n)
{
	int	size;

	size = 0;
	while (n)
	{
		size++;
		n /= 16;
	}
	return (size);
}

static int	ft_hex_address(unsigned long long n)
{
	char	*base_16;
	int		size;

	size = size_hex_address(n);
	base_16 = "0123456789abcdef";
	if (n < 16)
	{
		if (ft_print_char(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		ft_hex_address(n / 16);
		ft_hex_address(n % 16);
	}
	return (size);
}

int	ft_print_ptr(void *ptr)
{
	int	n;

	if (ft_print_str("0x") == -1)
		return (-1);
	n = ft_hex_address((unsigned long long)ptr);
	if (n != 0)
		return (n + 2); // for '0x'
	else
		return (3);
}
