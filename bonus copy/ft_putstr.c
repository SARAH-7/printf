/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:20:36 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/23 20:16:13 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, t_spec *result)
{
	int	counter;
	int	index;

	index = 0;
	counter = 0;
	if (!s && result->width == 0 && result->flag_precision == 0)
	{
		write(1, "(null)", 6);
		counter += 6;
		return (counter);
	}
	if (!s && (result->width - 6) > 0)
	{
		while ((result->width - 6) > 0)
		{
			counter += ft_putchar(' ');
			result->width--;
		}
		write(1, "(null)", 6);
		counter += 6;
		return (counter);
	}
	if ((result && result->flag_space == 1))
		counter = flag_space(counter, result);
	if (result && result->flag_precision == 1 && flag_right_padding == 0)
	{
		if (result->width == 0 || (ft_strlen(s) == 0))
			return (0);
		if (result->minimum_width > 0)
		{
			if (ft_strlen(s) >= result->minimum_width)
				result->width -= result->minimum_width;
			else
				result->width -= ft_strlen(s);
			// printf("\nwidth %d\n", result->width);
			counter = flag_space(counter, result);
			while (s[index] != '\0' && (result->minimum_width-- > 0))
				counter += write(1, &s[index++], 1);
		}
		else
		{
			while (s[index] != '\0' && (result->width-- > 0))
				counter += write(1, &s[index++], 1);
		}
		result->flag_precision = 0;
		return (counter);
	}
	if (((result->width - ft_strlen(s)) > 0) && result->flag_right_padding == 0)
	{
		result->width -= ft_strlen(s);
		counter = flag_space(counter, result);
	}
	if (s)
		counter += write(1, s, ft_strlen(s));
	if (result && result->flag_right_padding == 1)
	{
		result->width -= ft_strlen(s);
		counter = flag_right_padding(counter, result);
	}
	return (counter);
}
