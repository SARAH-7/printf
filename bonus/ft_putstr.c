/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:20:36 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/26 21:46:13 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, t_spec *result)
{
	int	counter;

	if (!s)
		s = "(null)";
	counter = 0;
	if (!s && (result->width - 6) < 0 && result->flag_precision == 0)
		null_string(&counter);
	if (!s && (result->width - 6) > 0)
		return (null_with_width(counter, result));
	if ((result && result->flag_space == 1))
		flag_space(&counter, result);
	if (result->flag_precision == 1 && result->flag_right_padding == 0)
		return (counter + string_precision(s, counter, result));
	if (((result->width - ft_strlen(s)) > 0) && result->flag_right_padding == 0)
	{
		result->width -= ft_strlen(s);
		flag_space(&counter, result);
	}
	if (s && result->flag_right_padding == 0)
		counter += write(1, s, ft_strlen(s));
	if (result && result->flag_right_padding == 1)
		string_flag_right_padding(s, &counter, result);
	return (counter);
}
