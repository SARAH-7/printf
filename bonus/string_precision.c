/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:51:17 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 22:27:53 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_precision(char *s, int counter, t_spec *result)
{
	int	index;

	index = 0;
	if (result->width == 0 || (ft_strlen(s) == 0))
		return (0);
	if (result->minimum_width > 0)
	{
		if (ft_strlen(s) >= result->minimum_width)
			result->width -= result->minimum_width;
		else
			result->width -= ft_strlen(s);
		flag_space(&counter, result);
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
