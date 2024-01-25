/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negtaive_signed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:37:12 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 23:05:08 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	negtaive_signed(unsigned int n, int *counter, t_spec *result)
{
	if (result && result->flag_zero == 1)
	{
		if ((long)n >= 4294967295)
			result->width -= 10;
		else
			result->width += n;
		while (result->width-- > 0)
			*counter += ft_putchar('0');
		result->flag_zero = 0;
	}
	if (result && result->flag_precision == 1)
	{
		result->width -= 10;
		while (result->width-- > 0)
			*counter += ft_putchar('0');
		result->flag_precision = 0;
	}
}
