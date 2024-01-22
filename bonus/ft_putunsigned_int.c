/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:13:11 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/22 12:48:46 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_int(unsigned int n, int counter, t_spec *result)
{
	int		padding_len;
	char	*num_save;

	num_save = ft_itoa(n);
	padding_len = 0;
	if ((int)n < 0)
	{
		if (result && result->flag_zero == 1)
		{
			if ((long)n >= 4294967295)
				padding_len = result->width - 10;
			else
				padding_len = result->width + n;
			while (padding_len-- > 0)
				counter += ft_putchar('0');
			result->flag_zero = 0;
		}
		if (result && result->flag_precision == 1 && n != 0)
		{
			if (n < 0)
			{
				n *= -1;
				free(num_save);
				num_save = ft_itoa(n);
			}
		}
	}
	else
	{
		if (result && result->flag_zero == 1)
		{
			padding_len = result->width - ft_strlen(num_save);
			while (padding_len-- > 0)
				counter += ft_putchar('0');
			result->flag_zero = 0;
		}
		if (result && result->flag_precision == 1 && n != 0)
		{
			if ((long)n >= 4294967295)
				padding_len = result->width - 10;
			if (n <= 2147483647)
				padding_len = result->width - ft_strlen(num_save);
			else if ((int)n == -2147483647)
				padding_len = result->width;
			else
				padding_len = 0;
			while (padding_len-- > 0)
				counter += ft_putchar('0');
			result->flag_precision = 0;
		}
	}
	free(num_save);
	if (n > 9)
		counter = ft_putnbr(n / 10, counter, result);
	return (counter + ft_putchar(n % 10 + '0'));
}
