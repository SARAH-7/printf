/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:43:11 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/24 19:23:21 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	minimum_width(const char **format, t_spec *result)
{
	int	malloc_size;
	int	index;

	malloc_size = 0;
	index = 0;
	(*format)++;
	while (**format >= '0' && **format <= '9')
	{
		malloc_size++;
		(*format)++;
	}
	result->width_string = (char *)malloc(malloc_size + 1);
	*format -= malloc_size;
	while (malloc_size--)
		result->width_string[index++] = *(*format)++;
	result->width_string[index] = '\0';
	result->minimum_width = atoi(result->width_string);
	free(result->width_string);
	result->flag_precision = 1;
	return (result->minimum_width);
}
