/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basianno <basianno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:06:34 by basianno          #+#    #+#             */
/*   Updated: 2026/11/09 14:27:59 by basianno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("%d\n", printf("%x\n", 255));
	printf("\n");
	printf("%u\n", ft_printf("%x\n", 255));
}
