/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:09:07 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/24 14:16:19 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int counter, t_spec *result)
{
	char	*num_save;

	num_save = ft_itoa(n);
	if (n < 0)
	{
		counter += ft_putchar('-');
		result->flag_space = 0;
	}
	if (result && result->flag_positive_sign == 1)
	{
		if (n >= 0)
			counter += ft_putchar('+');
		result->flag_positive_sign = 0;
	}
	if (result && result->flag_zero == 1)
	{
		result->width -= ft_strlen(num_save);
		while (result->width-- > 0)
			counter += ft_putchar('0');
		result->flag_zero = 0;
	}
	if (result && result->flag_precision == 1)
	{
		if (n < 0)
		{
			n *= -1;
			free(num_save);
			num_save = ft_itoa(n);
		}
		if (n <= 2147483647)
			result->width -= ft_strlen(num_save);
		else
			result->width = 0;
		while (result->width-- > 0)
			counter += ft_putchar('0');
		result->flag_precision = 0;
	}
	if (result && result->flag_space == 1)
	{
		counter += ft_putchar(' ');
		result->flag_space = 0;
	}
	free(num_save);
	if (n == -2147483648)
		return (counter + ft_putstr("2147483648", result));
	if (n < 0)
		return (ft_putnbr(-n, counter, result));
	if (n > 9)
		counter = ft_putnbr(n / 10, counter, result);
	counter += ft_putchar(n % 10 + '0');
	return (counter);
}
