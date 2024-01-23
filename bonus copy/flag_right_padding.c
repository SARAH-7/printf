/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_right_padding.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:00:23 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/23 16:24:42 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_right_padding(int counter, t_spec *result)
{
	while (result->width-- > 0)
		counter += ft_putchar(' ');
	result->flag_right_padding = 0;
	return (counter);
}