/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_length_counter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:55:28 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 23:00:15 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_length_counter(unsigned long n, int *hex_counter)
{
	while (n >= 16)
	{
		(*hex_counter)++;
		n /= 16;
	}
}
