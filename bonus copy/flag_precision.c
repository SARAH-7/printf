/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:23:27 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/23 14:01:39 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_precision(int counter, int hex_counter, t_spec *result)
{
	result->width -= hex_counter;
	while (result->width-- > 0)
		counter += ft_putchar('0');
	result->flag_precision = 0;
	return (counter);
}
