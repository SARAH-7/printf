/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:13:11 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/27 18:20:57 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_int(unsigned int n, int counter, t_spec *result)
{
	char	*num_save;

	num_save = ft_itoa(n);
	if ((int)n < 0)
		negtaive_signed(n, &counter, result);
	else
	{
		if (result->flag_zero == 1)
			flag_zero(&counter, ft_strlen(num_save), result);
		if (result->flag_precision == 1)
			flag_precision(&counter, ft_strlen(num_save), result);
	}
	free(num_save);
	if (n > 9)
		counter = ft_putnbr(n / 10, counter, result);
	return (counter + ft_putchar(n % 10 + '0'));
}
