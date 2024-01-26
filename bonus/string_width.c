/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:29:14 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 19:56:50 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_width(const char **format, t_spec *result)
{
	int	malloc_size;
	int	index;

	malloc_size = 0;
	index = 0;
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
	result->width = atoi(result->width_string);
	free(result->width_string);
	if (**format == '.')
		result->minimum_width = minimum_width(format, result);
	return (result->width);
}
