/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:13:11 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/23 14:09:06 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_int(unsigned int n, int counter, t_spec *result)
{
	char	*num_save;

	num_save = ft_itoa(n);
	if ((int)n < 0)
	{
		if (result && result->flag_zero == 1)
		{
			if ((long)n >= 4294967295)
				result->width -= 10;
			else
				result->width += n;
			while (result->width-- > 0)
				counter += ft_putchar('0');
			result->flag_zero = 0;
		}
		if (result && result->flag_precision == 1 && n != 0)
		{
			result->width -= 10;
			while (result->width-- > 0)
				counter += ft_putchar('0');
			result->flag_precision = 0;
		}
	}
	else
	{
		if (result && result->flag_zero == 1)
		{
			result->width -= ft_strlen(num_save);
			while (result->width-- > 0)
				counter += ft_putchar('0');
			result->flag_zero = 0;
		}
		if (result && result->flag_precision == 1 && n >= 0)
		{
			if ((long)n >= 4294967295)
				result->width -= 10;
			if (n <= 2147483647)
				result->width -= ft_strlen(num_save);
			else
				result->width = 0;
			while (result->width-- > 0)
				counter += ft_putchar('0');
			result->flag_precision = 0;
		}
	}
	free(num_save);
	if (n > 9)
		counter = ft_putnbr(n / 10, counter, result);
	return (counter + ft_putchar(n % 10 + '0'));
}
