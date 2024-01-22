/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:09:07 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/21 21:31:43 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long n, int counter, t_spec *result)
{
	int		padding_len;
	char	*num_save;

	padding_len = 0;
	num_save = ft_itoa(n);
	if (n < 0)
		counter += ft_putchar('-');
	if (result && result->flag_zero == 1)
	{
		padding_len = result->width - ft_strlen(num_save);
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
		if (n <= 2147483647)
			padding_len = result->width - ft_strlen(num_save);
		else
			padding_len = 0;
		while (padding_len-- > 0)
			counter += ft_putchar('0');
		result->flag_precision = 0;
	}
	if (result && result->flag_blank == 1)
	{
		padding_len = result->width - ft_strlen(num_save);
		while (padding_len-- > 0)
			counter += ft_putchar(' ');
		result->flag_blank = 0;
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
