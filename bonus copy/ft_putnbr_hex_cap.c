/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_cap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:19:19 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/23 14:03:19 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_cap(unsigned long long n, t_spec *result)
{
	const char	*hex_chars;
	int			counter;
	char		*digit;
	int			hex_counter;
	long		num_cp;

	num_cp = n;
	hex_counter = 1;
	digit = ft_itoa(n);
	counter = 0;
	while (num_cp >= 16)
	{
		hex_counter++;
		num_cp /= 16;
	}
	if (result && result->flag_zero == 1)
		counter = flag_zero(n, counter, hex_counter, result);
	if (result && result->flag_precision == 1 && n != 0)
		counter = flag_precision(counter, hex_counter, result);
	if (result && result->flag_alternate_form == 1 && n != 0)
	{
		counter += ft_putstr("0X", result);
		counter = flag_alternate_form(n, counter, hex_counter, result);
	}
	free(digit);
	hex_chars = "0123456789ABCDEF";
	if (n >= 16)
		counter += ft_putnbr_hex_cap(n / 16, result);
	counter += ft_putchar(hex_chars[n % 16]);
	return (counter);
}
