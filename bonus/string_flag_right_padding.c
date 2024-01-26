/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_flag_right_padding.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:53:15 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/26 20:27:09 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_flag_right_padding(char *s, int *counter, t_spec *result)
{
	int	index;

	index = 0;
	if (result->minimum_width > 0)
	{
		while (s[index] && result->minimum_width-- > 0)
			*counter += write(1, &s[index++], 1);
		result->width -= *counter;
		flag_right_padding(counter, result->width);
	}
	else
	{
		*counter += write(1, s, ft_strlen(s));
		result->width -= *counter;
		flag_right_padding(counter, result->width);
	}
}
