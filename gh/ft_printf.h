/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:02:58 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/27 18:17:43 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_spec
{
	int		flag_zero;
	int		flag_right_padding;
	int		flag_alternate_form;
	int		flag_positive_sign;
	int		flag_precision;
	int		flag_space;
	int		width;
	char	*width_string;
	int		check_flag;
	int		minimum_width;
}			t_spec;

int			ft_putchar(char c);

int			ft_strlen(const char *s);

int			ft_putstr(char *s, t_spec *flags);

int			ft_putnbr(int n, int counter, t_spec *flags);

int			ft_putunsigned_int(unsigned int n, int counter, t_spec *flags);

int			ft_putnbr_hex(unsigned long n, t_spec *flags);

int			ft_putnbr_hex_cap(unsigned int n, t_spec *flags);

int			ft_putpointer(void *ptr, t_spec *flags);

int			ft_printf(const char *format, ...);

int			ft_atoi(const char *str);

char		*ft_itoa(long n);

void		flag_space(int *counter, t_spec *result);

void		flag_right_padding(int *counter, int width);

void		flag_alternate_form(unsigned int n, int *counter,
				int hex_counter, t_spec *result);

void		flag_precision(int *counter, int string_length, t_spec *result);

void		flag_zero(int *counter,
				int hex_counter, t_spec *result);

int			string_width(const char **format, t_spec *result);

int			minimum_width(const char **format, t_spec *result);

int			precentage_format(int counter, t_spec *result);

int			string_precision(char *s, int counter, t_spec *result);

int			null_with_width(int counter, t_spec *result);

void		null_string(int *counter);

void		negtaive_signed(unsigned int n, int *counter, t_spec *result);

void		hex_length_counter(unsigned long n, int *hex_counter);

void		flag_check(const char **format, t_spec *result);

int			putchar_counter(va_list args, int counter, t_spec *result);

int			putnbr_counter(va_list args, int counter, t_spec *result);

int			putunsigned_counter(va_list args, int counter, t_spec *result);

int			puthex_counter(va_list args, int counter, t_spec *result);

int			puthex_cap_counter(va_list args, int counter, t_spec *result);

void		string_flag_right_padding(char *s, int *counter, t_spec *result);

void		putnegative_and_flag_space(int *counter, t_spec *result);

void		flag_positive_sign(int n, int *counter, t_spec *result);

void		num_precision(int n, char *num_save, int *counter, t_spec *result);

#endif