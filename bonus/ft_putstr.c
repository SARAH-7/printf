/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:20:36 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/22 19:07:09 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, t_spec *result)
{
	int	counter;
	int	width;
	int	padding_len;

	padding_len = 0;
	width = result->width;
	counter = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		counter = 6;
		if (result->flag_right_padding == 1)
			counter = 0;
	}
	if (result && result->flag_space == 1)
		counter = flag_space(counter, result);
	if (result && result->flag_precision == 1)
	{
		if (result->width == 0 || (ft_strlen(s) == 0))
			return (0);
		while (s[padding_len] != '\0' && (result->width-- > 0))
			counter += write(1, &s[padding_len++], 1);
		result->flag_precision = 0;
		return (counter);
	}
	if (s)
		counter += write(1, s, strlen(s));
	if (result && result->flag_blank == 1)
	{
		while ((result->width)-- > 0)
			counter += ft_putchar(' ');
		result->flag_blank = 0;
	}
	if (result && result->flag_right_padding == 1)
		counter = flag_right_padding(s, counter, result);
	return (counter);
}
