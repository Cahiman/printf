/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basianno <basianno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:58:16 by basianno          #+#    #+#             */
/*   Updated: 2026/11/10 09:43:44 by basianno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_char(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(*args, int)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'x')
		return (ft_base(va_arg(*args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_base(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	if (c == 'u')
		return (ft_base(va_arg(*args, unsigned int), "0123456789"));
	if (c == 'p')
		return (ft_hex(va_arg(*args, void *)));
	return (ft_putchar('%') + ft_putchar(c));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (va_end(args), -1);
			count += check_char(format[i + 1], &args);
			i++;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
