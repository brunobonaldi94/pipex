/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:02:38 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/20 22:01:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_uintstr_with_precision(char *int_str,
			size_t precision)
{
	size_t	padding_zero_len;
	size_t	int_str_len;
	char	*int_str_after_precision;

	int_str_after_precision = (char *)malloc(sizeof(char)
			* (precision + 1));
	int_str_len = ft_strlen(int_str);
	padding_zero_len = (size_t)precision - int_str_len;
	ft_memset(int_str_after_precision, '0', padding_zero_len);
	ft_memcpy(int_str_after_precision + padding_zero_len, int_str,
		int_str_len);
	int_str_after_precision[precision] = '\0';
	return (int_str_after_precision);
}

char	*apply_precision_uint(char *uint_str, t_format_opt *format_opt,
			unsigned int uint_arg)
{
	int				precision;
	char			*uint_str_after_precision;
	size_t			uint_str_len;

	precision = (format_opt)->precision;
	uint_str_len = ft_strlen(uint_str);
	if (precision >= 0)
		remove_flag(format_opt, '0');
	if (precision > 0 && (size_t)precision > uint_str_len)
		uint_str_after_precision = format_uintstr_with_precision(uint_str,
				precision);
	else if (precision == 0 && uint_arg == 0)
		uint_str_after_precision = ft_strdup("");
	else
		uint_str_after_precision = ft_strdup(uint_str);
	free(uint_str);
	return (uint_str_after_precision);
}

void	ft_print_uint(va_list list_args, char specifier,
	int *number_chars_printed, t_format_opt *format_opt)
{
	unsigned int		uint_arg;
	char				*uint_str;
	char				*final_uint_str;
	size_t				uint_str_len;

	uint_arg = va_arg(list_args, unsigned int);
	uint_str = ft_itoa_base(uint_arg, 10, specifier);
	uint_str = apply_precision_uint(uint_str, format_opt, uint_arg);
	final_uint_str = ft_min_width(format_opt, uint_str);
	free(uint_str);
	ft_putstr_fd(final_uint_str, 1);
	uint_str_len = ft_strlen(final_uint_str);
	(*number_chars_printed) += uint_str_len;
	free(final_uint_str);
}
