/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_alternate_form.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:12:59 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 22:13:30 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_alternate_form(unsigned int n, int *counter,
int hex_counter, t_spec *result)
{
	if (n <= 2147483647)
		result->width -= hex_counter;
	else
		result->width = 0;
	while (result->width-- > 0)
		*counter += ft_putchar('0');
	result->flag_alternate_form = 0;
}
