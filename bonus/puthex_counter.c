/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:23:46 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 19:24:28 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthex_counter(va_list args, int counter, t_spec *result)
{
	counter += ft_putnbr_hex((unsigned int)va_arg(args, unsigned int), result);
	while (result->flag_right_padding == 1 && counter < result->width)
		counter += ft_putchar(' ');
	return (counter);
}
