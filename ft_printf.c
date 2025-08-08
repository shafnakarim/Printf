/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srayees <srayees@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:45:53 by srayees           #+#    #+#             */
/*   Updated: 2025/08/08 16:24:25 by srayees          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(const char input, va_list args)
{
	if (input == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (input == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (input == 'd' || input == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (input == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (input == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if (input == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	else if (input == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (input == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	int			printed;
	int			ret;

	printed = 0;
	va_start(args, input);
	while (*input)
	{
		if (*input == '%' && *(input + 1))
		{
			input++;
			ret = ft_type(*input, args);
		}
		else
			ret = ft_print_char(*input);
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
}
