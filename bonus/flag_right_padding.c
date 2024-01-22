/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_right_padding.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:00:23 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/22 19:06:31 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_right_padding(char *s, int counter, t_spec *result)
{
	int	padding_len;

	padding_len = 0;
	if (result && result->flag_right_padding == 1)
	{
		padding_len = result->width - ft_strlen(s);
		while (padding_len-- > 0)
			counter += ft_putchar(' ');
		result->flag_right_padding = 0;
	}
	return (counter);
}
