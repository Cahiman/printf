/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basianno <basianno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:58:16 by basianno          #+#    #+#             */
/*   Updated: 2026/11/04 18:38:33 by basianno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	check_char(char c, va_list *args)
{
	if (c == 'c')
		va_arg()
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
			check_char(format[i + 1]);
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}