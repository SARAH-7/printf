/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:02:58 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/22 20:01:31 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct format_specifier
{
	int		flag_zero;
	int		flag_right_padding;
	int		flag_alternate_form;
	int		flag_blank;
	int		flag_positive_sign;
	int		flag_precision;
	int		flag_space;
	int		width;
	char	width_string[242];
	int		check_flag;
}			t_spec;

int			ft_putchar(char c);

int			ft_strlen(const char *s);

int			ft_putstr(char *s, t_spec *flags);

int			ft_putnbr(long long n, int counter, t_spec *flags);

int			ft_putunsigned_int(unsigned int n, int counter, t_spec *flags);

int			ft_putnbr_hex(unsigned long long n, t_spec *flags);

int			ft_putnbr_hex_cap(unsigned long long n, t_spec *flags);

int			ft_putpointer(void *ptr, t_spec *flags);

int			ft_printf(const char *format, ...);

int			ft_atoi(const char *str);

char		*ft_itoa(long n);

int			flag_space(int counter, t_spec *result);

int			flag_right_padding(char *s, int counter, t_spec *result);

int			flag_alternate_form(unsigned long long n, int counter, int hex_counter, t_spec *result);

int			flag_precision(unsigned long long n, int counter, int hex_counter, t_spec *result);

int			flag_zero(unsigned long long n, int counter, int hex_counter, t_spec *result);

#endif