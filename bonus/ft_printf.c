/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:05:58 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/22 20:14:31 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formats_fun(const char **format, va_list args)
{
	int		counter;
	t_spec	result;
	int		index;

	index = 0;
	counter = 0;
	result.width = 0;
	result.flag_precision = 0;
	result.flag_blank = 0;
	result.flag_zero = 0;
	result.flag_alternate_form = 0;
	result.flag_space = 0;
	result.flag_positive_sign = 0;
	while (**format == ' ')
	{
		result.flag_space = 1;
		(*format)++;
	}
	while (**format == '#')
	{
		result.flag_alternate_form = 1;
		(*format)++;
	}
	while (**format == '+')
	{
		result.flag_positive_sign = 1;
		(*format)++;
	}
	if (**format >= '1' && **format <= '9')
		result.flag_blank = 1;
	while (**format == '-')
	{
		result.flag_right_padding = 1;
		(*format)++;
	}
	while (**format == '0')
	{
		result.flag_zero = 1;
		(*format)++;
	}
	while (**format == '.')
	{
		result.flag_precision = 1;
		while (**format == '0')
			(*format)++;
		(*format)++;
	}
	if (**format >= '0' && **format <= '9')
	{
		while (**format >= '0' && **format <= '9')
			result.width_string[index++] = *(*format)++;
		result.width = atoi(result.width_string);
	}
	if (**format == 'c')
	{
		counter += ft_putchar(va_arg(args, int));
		if (result.flag_right_padding == 1)
		{
			while (--result.width > 0)
				counter += ft_putchar(' ');
			result.flag_blank = 0;
		}
	}
	if (**format == 's')
		counter += ft_putstr(va_arg(args, char *), &result);
	if (**format == 'd' || **format == 'i')
	{
		counter += ft_putnbr(va_arg(args, int), counter, &result);
		if (result.flag_right_padding == 1)
		{
			while (counter < result.width)
				counter += ft_putchar(' ');
		}
		result.flag_right_padding = 0;
	}
	if (**format == 'u')
	{
		counter += ft_putunsigned_int(va_arg(args, long), counter, &result);
		if (result.flag_right_padding == 1)
		{
			while (counter < result.width)
				counter += ft_putchar(' ');
		}
		result.flag_right_padding = 0;
	}
	if (**format == 'p')
		counter += ft_putpointer(va_arg(args, void *), &result);
	if (**format == 'x')
	{
		counter += ft_putnbr_hex((unsigned int)va_arg(args, unsigned int),
				&result);
		if (result.flag_right_padding == 1)
		{
			while (counter < result.width)
				counter += ft_putchar(' ');
		}
		result.flag_right_padding = 0;
	}
	if (**format == 'X')
	{
		counter += ft_putnbr_hex_cap((unsigned int)va_arg(args, unsigned int),
				&result);
		if (result.flag_right_padding == 1)
		{
			while (counter < result.width)
				counter += ft_putchar(' ');
		}
		result.flag_right_padding = 0;
	}
	if (**format == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		str_counter;
	int		counter;

	counter = 0;
	str_counter = 0;
	va_start(args, format);
	while (*format != '\0')
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
// 	printf("\nmine: (%d)\n", ft_printf(" %01x ", 0));
// 	printf("\ntheirs: (%d)\n", printf(" %01x ", 0));
// }
