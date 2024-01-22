/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:11:07 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/22 18:57:44 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_space(int counter, t_spec *result)
{
	if (result && result->flag_space == 1)
	{
		while (result->width-- > 0)
			counter += ft_putchar(' ');
		result->flag_space = 0;
	}
	return (counter);
}
