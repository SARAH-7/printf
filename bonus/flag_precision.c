/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:23:27 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/22 19:25:49 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_precision(unsigned long long n, int counter, int hex_counter, t_spec *result)
{
	int	padding_len;

	padding_len = 0;
	if (n <= 2147483647)
		padding_len = result->width - hex_counter;
	else
		padding_len = 0;
	while (padding_len-- > 0)
		counter += ft_putchar('0');
	result->flag_precision = 0;
	return (counter);
}
