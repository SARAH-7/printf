/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_cap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:19:19 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/27 18:19:58 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_cap(unsigned int n, t_spec *result)
{
	const char	*hex_chars;
	int			counter;
	char		*digit;
	int			hex_counter;

	hex_counter = 1;
	digit = ft_itoa(n);
	counter = 0;
	hex_length_counter(n, &hex_counter);
	if (result->flag_zero == 1)
		flag_zero(&counter, hex_counter, result);
	if (result->flag_precision == 1)
		flag_precision(&counter, hex_counter, result);
	if (result->flag_alternate_form == 1 && n > 0)
	{
		counter += ft_putstr("0X", result);
		flag_alternate_form(n, &counter, hex_counter, result);
	}
	free(digit);
	hex_chars = "0123456789ABCDEF";
	if (n >= 16)
		counter += ft_putnbr_hex_cap(n / 16, result);
	counter += ft_putchar(hex_chars[n % 16]);
	return (counter);
}
