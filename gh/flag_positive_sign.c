/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_positive_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:15:52 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/26 14:16:37 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_positive_sign(int n, int *counter, t_spec *result)
{
	if (n >= 0)
		*counter += ft_putchar('+');
	result->flag_positive_sign = 0;
}
