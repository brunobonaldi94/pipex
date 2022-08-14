/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:10:54 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/20 22:01:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_hexstr_with_precision(char *int_str,
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
	ft_memcpy(int_str_after_precision + padding_zero_len,
		int_str, int_str_len);
	int_str_after_precision[precision] = '\0';
	return (int_str_after_precision);
}

char	*apply_precision_hex(char *hex_str, t_format_opt *format_opt,
			unsigned int hex_arg)
{
	int				precision;
	char			*hex_str_after_precision;
	size_t			hex_str_len;

	precision = (format_opt)->precision;
	hex_str_len = ft_strlen(hex_str);
	if (precision >= 0)
		remove_flag(format_opt, '0');
	if (precision > 0 && (size_t)precision > hex_str_len)
		hex_str_after_precision = format_hexstr_with_precision(hex_str,
				precision);
	else if (precision == 0 && hex_arg == 0)
		hex_str_after_precision = ft_strdup("");
	else
		hex_str_after_precision = ft_strdup(hex_str);
	free(hex_str);
	return (hex_str_after_precision);
}

char	*apply_sharp_flag(t_format_opt *format_opt,
			char *hex_str, char specifier, unsigned int hex_arg)
{
	char	*hex_str_with_prefix;
	char	hex_prefix[3];

	if (has_flag(format_opt, '#') && hex_arg != 0)
	{
		hex_prefix[0] = '0';
		hex_prefix[1] = specifier;
		hex_prefix[2] = '\0';
		hex_str_with_prefix = ft_strjoin(hex_prefix, hex_str);
	}
	else
		hex_str_with_prefix = ft_strdup(hex_str);
	free(hex_str);
	return (hex_str_with_prefix);
}

void	ft_print_hex(va_list list_args, char specifier,
	int *number_chars_printed, t_format_opt *format_opt)
{
	unsigned int	hex_arg;
	size_t			hex_str_len;
	char			*hex_str;
	char			*final_hex_str;

	hex_arg = va_arg(list_args, unsigned int);
	hex_str = ft_itoa_base(hex_arg, 16, specifier);
	hex_str = apply_precision_hex(hex_str, format_opt, hex_arg);
	hex_str = apply_sharp_flag(format_opt, hex_str, specifier, hex_arg);
	final_hex_str = ft_min_width(format_opt, hex_str);
	free(hex_str);
	ft_putstr_fd(final_hex_str, 1);
	hex_str_len = ft_strlen(final_hex_str);
	(*number_chars_printed) += hex_str_len;
	free(final_hex_str);
}
