/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_string_with_width.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:34:10 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 23:09:27 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	null_with_width(int *counter, t_spec *result)
{
	while ((result->width - 6) > 0)
	{
		*counter += ft_putchar(' ');
		result->width--;
	}
	write(1, "(null)", 6);
	*counter += 6;
}
