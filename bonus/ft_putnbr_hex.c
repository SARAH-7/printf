/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:14:39 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/25 23:00:47 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long n, t_spec *result)
{
	const char	*hex_chars;
	int			counter;
	char		*digit;
	int			hex_counter;

	hex_counter = 1;
	digit = ft_itoa(n);
	counter = 0;
	hex_length_counter(n, &hex_counter);
	if (result && result->flag_zero == 1)
		flag_zero(&counter, hex_counter, result);
	if (result && result->flag_precision == 1)
		flag_precision(&counter, hex_counter, result);
	if (result && result->flag_alternate_form == 1 && n > 0)
	{
		counter += ft_putstr("0x", result);
		flag_alternate_form(n, &counter, hex_counter, result);
	}
	free(digit);
	hex_chars = "0123456789abcdef";
	if (n >= 16)
		counter += ft_putnbr_hex(n / 16, result);
	counter += ft_putchar(hex_chars[n % 16]);
	return (counter);
}
