/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:11:07 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 22:25:51 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_space(int *counter, t_spec *result)
{
	while (result->width-- > 0)
		*counter += ft_putchar(' ');
	result->flag_space = 0;
}
