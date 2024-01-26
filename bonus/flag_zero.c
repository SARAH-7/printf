/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:29:00 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 23:00:34 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_zero(int *counter, int hex_counter, t_spec *result)
{
	result->width -= hex_counter;
	while (result->width-- > 0)
		*counter += ft_putchar('0');
	result->flag_zero = 0;
}
