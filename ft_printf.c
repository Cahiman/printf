/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basianno <basianno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:58:16 by basianno          #+#    #+#             */
/*   Updated: 2026/11/06 13:41:09 by basianno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_char(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (c == 'x')
		return (ft_putstr(va_arg(*args, unsigned int)));

	return 0;
}

int ft_printf(const char *format, ...)
{
	int	i;
	va_list args;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			check_char(format[i + 1], &args);
			i++;
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}