/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:39:55 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/20 22:01:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_intstr_with_precision(int is_negative, char *int_str,
			size_t precision)
{
	size_t	padding_zero_len;
	size_t	int_str_len;
	char	*int_str_after_precision;
	size_t	precision_with_negative_byte;

	precision_with_negative_byte = precision + is_negative;
	int_str_after_precision = (char *)malloc(sizeof(char)
			* (precision_with_negative_byte + 1));
	if (is_negative)
		int_str_after_precision[0] = '-';
	int_str_len = ft_strlen(int_str);
	padding_zero_len = (size_t)precision_with_negative_byte - int_str_len;
	ft_memset(int_str_after_precision + is_negative, '0', padding_zero_len);
	ft_memcpy(int_str_after_precision + padding_zero_len + is_negative,
		int_str + is_negative, int_str_len - is_negative);
	int_str_after_precision[precision_with_negative_byte] = '\0';
	return (int_str_after_precision);
}

char	*apply_precision_int(char *int_str, t_format_opt *format_opt,
			int int_arg)
{
	int				precision;
	char			*int_str_after_precision;
	size_t			int_str_len;
	int				is_negative;

	precision = (format_opt)->precision;
	is_negative = 0;
	if (int_arg < 0)
		is_negative = 1;
	int_str_len = ft_strlen(int_str);
	if (precision >= 0)
		remove_flag(format_opt, '0');
	if (precision > 0 && (size_t)precision > int_str_len - is_negative)
		int_str_after_precision = format_intstr_with_precision(is_negative,
				int_str, precision);
	else if (precision == 0 && int_arg == 0)
		int_str_after_precision = ft_strdup("");
	else
		int_str_after_precision = ft_strdup(int_str);
	free(int_str);
	return (int_str_after_precision);
}

void	manage_int_flags(t_format_opt *format_opt, char **int_str, int int_arg)
{
	char	*int_str_after_flags;

	if (int_arg < 0 && has_flag(format_opt, '0'))
		(*int_str)[0] = '0';
	if (int_arg >= 0 && has_flag(format_opt, '+'))
	{
		remove_flag(format_opt, ' ');
		int_str_after_flags = ft_strjoin("+", *int_str);
		free(*int_str);
		*int_str = int_str_after_flags;
	}
	if (has_flag(format_opt, ' ') && int_arg >= 0)
	{
		int_str_after_flags = ft_strjoin(" ", *int_str);
		free(*int_str);
		*int_str = int_str_after_flags;
	}
}

void	ft_print_int(va_list list_args, int *number_chars_printed,
	t_format_opt *format_opt)
{
	int		int_arg;
	char	*int_str;
	char	*final_int_str;
	size_t	int_str_len;

	int_arg = va_arg(list_args, int);
	int_str = ft_itoa(int_arg);
	int_str = apply_precision_int(int_str, format_opt, int_arg);
	manage_int_flags(format_opt, &int_str, int_arg);
	final_int_str = ft_min_width(format_opt, int_str);
	free(int_str);
	if (int_arg < 0 && has_flag(format_opt, '0'))
		final_int_str[0] = '-';
	ft_putstr_fd(final_int_str, 1);
	int_str_len = ft_strlen(final_int_str);
	(*number_chars_printed) += int_str_len;
	free(final_int_str);
}
