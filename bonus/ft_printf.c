/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:05:58 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/26 21:56:35 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_t_spec(t_spec *result)
{
	result->width = 0;
	result->flag_precision = 0;
	result->flag_zero = 0;
	result->flag_alternate_form = 0;
	result->flag_space = 0;
	result->flag_positive_sign = 0;
	result->minimum_width = 0;
	result->flag_right_padding = 0;
}

static int	formats_fun(const char **format, va_list args)
{
	int		counter;
	t_spec	result;

	counter = 0;
	init_t_spec(&result);
	flag_check(format, &result);
	if (**format >= '0' && **format <= '9')
		result.width = string_width(format, &result);
	if (**format == 'c')
		counter = putchar_counter(args, counter, &result);
	if (**format == 's')
		counter = ft_putstr(va_arg(args, char *), &result);
	if (**format == 'd' || **format == 'i')
		counter = putnbr_counter(args, counter, &result);
	if (**format == 'u')
		counter = putunsigned_counter(args, counter, &result);
	if (**format == 'p')
		counter += ft_putpointer(va_arg(args, void *), &result);
	if (**format == 'x')
		counter = puthex_counter(args, counter, &result);
	if (**format == 'X')
		counter = puthex_cap_counter(args, counter, &result);
	if (**format == '%')
		counter = precentage_format(counter, &result);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		str_counter;

	str_counter = 0;
	va_start(args, format);
	while (format && *format != '\0')
	{
		if (*format != '%')
			str_counter += ft_putchar(*format);
		else
		{
			format++;
			str_counter += formats_fun(&format, args);
		}
		format++;
	}
	va_end(args);
	return (str_counter);
}

// int	main(void)
// {
// 	printf("%d", ft_printf(" %.1i ", -9));
// 	printf("\n");
// 	printf("%d", printf(" %.1i ", -9));
// 	// printf("%d", ft_printf("%5c, %5c, %5c", '5', 'x', '\n'));
// 	// printf("\n");
// 	// printf("%d", printf("%5c, %5c, %5c", '5', 'x', '\n'));
// }
