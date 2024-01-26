/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:09:46 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 19:13:52 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_check(const char **format, t_spec *result)
{
	while (**format == ' ' || **format == '#' || **format == '+'
		|| **format == '-' || **format == '0' || **format == '.')
	{
		if (**format == ' ')
			result->flag_space = 1;
		if (**format == '#')
			result->flag_alternate_form = 1;
		if (**format == '+')
			result->flag_positive_sign = 1;
		if (**format == '-')
			result->flag_right_padding = 1;
		if (**format == '0')
			result->flag_zero = 1;
		if (**format == '.')
			result->flag_precision = 1;
		(*format)++;
	}
}
