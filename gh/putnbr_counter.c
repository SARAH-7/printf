/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:31:26 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 18:39:00 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_counter(va_list args, int counter, t_spec *result)
{
	counter += ft_putnbr(va_arg(args, int), counter, result);
	while (result->flag_right_padding == 1 && counter < result->width)
		counter += ft_putchar(' ');
	return (counter);
}
