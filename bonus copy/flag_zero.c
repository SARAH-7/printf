/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:29:00 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/23 14:02:38 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_zero(unsigned long long n, int counter, int hex_counter, t_spec *result)
{
	if ((int)n >= 0)
		result->width -= hex_counter;
	else if ((long)n >= 4294967295)
		result->width -= hex_counter;
	else
		result->width = 0;
	while (result->width-- > 0)
		counter += ft_putchar('0');
	result->flag_zero = 0;
	return (counter);
}
