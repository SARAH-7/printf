/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:03:40 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/22 19:10:34 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr, t_spec *result)
{
	int	counter;
	int	padding_len;

	padding_len = 0;
	counter = 0;
	counter += write(1, "0x", 2);
	counter += ft_putnbr_hex((unsigned long)ptr, result);
	if (result && result->flag_right_padding == 1)
	{
		padding_len = result->width - counter;
		while (padding_len-- > 0)
			counter += ft_putchar(' ');
		result->flag_right_padding = 0;
	}
	return (counter);
}
