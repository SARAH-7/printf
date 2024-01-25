/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precentage_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:50:00 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 23:15:10 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precentage_format(int *counter, t_spec *result)
{
	if (result->flag_right_padding == 1)
	{
		*counter += ft_putchar('%');
		result->width--;
		flag_right_padding(counter, result->width);
	}
	else
	{
		while (--result->width > 0)
			*counter += ft_putchar(' ');
		*counter += ft_putchar('%');
	}
}
