/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnegative_and_flag_space.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:11:27 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/26 14:12:07 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnegative_and_flag_space(int *counter, t_spec *result)
{
	*counter += ft_putchar('-');
	result->flag_space = 0;
}
