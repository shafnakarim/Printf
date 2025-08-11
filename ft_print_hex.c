/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srayees <srayees@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:43:22 by srayees           #+#    #+#             */
/*   Updated: 2025/08/11 11:23:59 by srayees          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, int uppercase)
{
	char	*hex;
	int		len;
	int		temp;

	len = 0;
	temp = 0;
	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		temp = ft_print_hex(n / 16, uppercase);
	if (temp == -1)
		return (-1);
	len += temp;
	if (write(1, &hex[n % 16], 1) == -1)
		return (-1);
	len += 1;
	return (len);
}
