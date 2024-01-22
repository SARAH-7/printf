/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:29:00 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/22 19:32:50 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_zero(unsigned long long n, int counter, int hex_counter, t_spec *result)
{
	int	padding_len;

	padding_len = 0;
	if ((int)n >= 0)
		padding_len = result->width - hex_counter;
	else if ((long)n >= 4294967295)
		padding_len = result->width - hex_counter;
	else
		padding_len = 0;
	while (padding_len-- > 0)
		counter += ft_putchar('0');
	result->flag_zero = 0;
	return (counter);
}
