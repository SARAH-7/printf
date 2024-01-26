/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:37:11 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/26 14:03:32 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	num_precision(int n, char *num_save, int *counter, t_spec *result)
{
	if (n < 0)
	{
		n *= -1;
		free(num_save);
		num_save = ft_itoa(n);
	}
	if (n <= 2147483647)
		result->width -= ft_strlen(num_save);
	else
		result->width = 0;
	while (result->width-- > 0)
		*counter += ft_putchar('0');
	result->flag_precision = 0;
}
