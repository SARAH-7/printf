/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_cap_counter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:27:40 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 19:38:07 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthex_cap_counter(va_list args, int counter, t_spec *result)
{
	counter += ft_putnbr_hex_cap(va_arg(args, unsigned int), result);
	while (result->flag_right_padding == 1 && counter < result->width)
		counter += ft_putchar(' ');
	return (counter);
}
