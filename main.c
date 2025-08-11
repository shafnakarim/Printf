/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srayees <srayees@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:41:15 by srayees           #+#    #+#             */
/*   Updated: 2025/08/11 11:57:45 by srayees          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	c = 'B';
	char	*str = "Hello";
	void	*ptr = str;
	int		n = -42;
	unsigned int u = 42;

	ft_printf("Char: %c\n", c);
	ft_printf("String: %s\n", str);
	ft_printf("Pointer: %p\n", ptr);
	ft_printf("NULL pointer: %p\n", NULL);
	ft_printf("Decimal: %d\n", n);
	ft_printf("Integer: %i\n", n);
	ft_printf("Unsigned: %u\n", u);
	ft_printf("Hex lowercase: %x\n", u);
	ft_printf("Hex uppercase: %X\n", u);
	ft_printf("Percent: %%\n");

	printf("\n--- Original printf for comparison ---\n");
	printf("Char: %c\n", c);
	printf("String: %s\n", str);
	printf("Pointer: %p\n", ptr);
	printf("NULL pointer: %p\n", NULL);
	printf("Decimal: %d\n", n);
	printf("Integer: %i\n", n);
	printf("Unsigned: %u\n", u);
	printf("Hex lowercase: %x\n", u);
	printf("Hex uppercase: %X\n", u);
	printf("Percent: %%\n");

	return (0);
}
