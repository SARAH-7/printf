/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunsigned_counter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:42:04 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 19:35:42 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putunsigned_counter(va_list args, int counter, t_spec *result)
{
	counter += ft_putunsigned_int((unsigned int)va_arg(args, unsigned int),
			counter, result);
	while (result->flag_right_padding == 1 && counter < result->width)
		counter += ft_putchar(' ');
	return (counter);
}
