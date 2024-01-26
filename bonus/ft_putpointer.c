/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:03:40 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/24 19:34:24 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr, t_spec *result)
{
	int	counter;

	counter = 0;
	counter += write(1, "0x", 2);
	counter += ft_putnbr_hex((unsigned long)ptr, result);
	if (result && result->flag_right_padding == 1)
	{
		result->width -= counter;
		while (result->width-- > 0)
			counter += ft_putchar(' ');
		result->flag_right_padding = 0;
	}
	return (counter);
}
