/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:09:07 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/26 16:18:37 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int counter, t_spec *result)
{
	char	*num_save;

	num_save = ft_itoa(n);
	if (n < 0)
		putnegative_and_flag_space(&counter, result);
	if (result && result->flag_positive_sign == 1)
		flag_positive_sign(n, &counter, result);
	if (result && result->flag_zero == 1)
		flag_zero(&counter, ft_strlen(num_save), result);
	if (result && result->flag_precision == 1)
		num_precision(n, num_save, &counter, result);
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
