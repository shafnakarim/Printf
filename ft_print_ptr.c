/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srayees <srayees@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:24:44 by srayees           #+#    #+#             */
/*   Updated: 2025/08/08 16:30:58 by srayees          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_ptr_hex(uintptr_t n)
{
	char	*hex;
	int		len;
	int		temp;

	hex = "0123456789abcdef";
	len = 0;
	if (n >= 16)
	{
		temp = print_ptr_hex(n / 16);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (write(1, &hex[n % 16], 1) == -1)
		;
	return (-1);
	len++;
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	int	len;
	int	temp;

	len = write(1, "0x", 2);
	if (len == -1)
		return (-1);
	temp = print_ptr_hex((uintptr_t)ptr);

	#include "ft_printf.h"

	int	handle_input(const char input, va_list args)
	{
		if (input == 'c')
			return (ft_putchar(va_arg(args, int)));
		else if (input == 's')
			return (ft_putstr(va_arg(args, char *)));
		else if (input == 'd' || input == 'i')
			return (ft_putnbr(va_arg(args, int)));
		else if (input == 'u')
			return (ft_put_unsigned(va_arg(args, unsigned int)));
		else if (input == 'x')
			return (ft_puthex(va_arg(args, unsigned int), 0));
		else if (input == 'X')
			return (ft_puthex(va_arg(args, unsigned int), 1));
		else if (input == 'p')
			return (ft_putptr(va_arg(args, void *)));
		else if (input == '%')
			return (ft_putchar('%'));
		return (0);
	}
	
	int	ft_printf(const char *input, ...)
	{
		va_list	args;
		int		printed;
		int		ret;
	
		printed = 0;
		va_start(args, input);
		while (*input)
		{
			if (*input == '%' && *(input + 1))
			{
				input++;
				ret = handle_input(*input, args);
			}
			else
				ret = ft_putchar(*input);
			if (ret == -1)
			{
				va_end(args);
				return (-1);
			}
			printed += ret;
			input++;
		}
		va_end(args);
		return (printed);
	}	if (temp == -1)
		return (-1);
	len += temp;
	return (len);
}
