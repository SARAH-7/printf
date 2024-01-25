/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:23:27 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 22:17:01 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_precision(int *counter, int string_length, t_spec *result)
{
	result->width -= string_length;
	while (result->width-- > 0)
		*counter += ft_putchar('0');
	result->flag_precision = 0;
}
