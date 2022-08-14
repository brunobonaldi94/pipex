/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:01:28 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/20 22:01:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_precision(t_format_opt *format_opt, char *str_arg)
{
	char	*str_arg_after_precision;

	if (format_opt->precision == 0)
		str_arg_after_precision = ft_strdup("");
	else if (format_opt->precision > 0
		&& (size_t)format_opt->precision < ft_strlen(str_arg))
			str_arg_after_precision = ft_substr(str_arg, 0,
				format_opt->precision);
	else
		str_arg_after_precision = ft_strdup(str_arg);
	return (str_arg_after_precision);
}

char	*apply_precision_null(t_format_opt *format_opt)
{
	char	*str_arg_null;

	if (format_opt->precision >= 6 || format_opt->precision == -1)
		str_arg_null = ft_strdup("(null)");
	else
		str_arg_null = ft_strdup("");
	return (str_arg_null);
}

void	ft_print_str(va_list list_args, int *number_chars_printed,
			t_format_opt *format_opt)
{
	char	*str_arg;
	char	*final_str_arg;
	char	*str_arg_after_precision;

	str_arg = va_arg(list_args, char *);
	if (str_arg == NULL)
	{
		str_arg_after_precision = apply_precision_null(format_opt);
		final_str_arg = ft_min_width(format_opt, str_arg_after_precision);
		free(str_arg_after_precision);
	}
	else
	{
		str_arg_after_precision = apply_precision(format_opt, str_arg);
		final_str_arg = ft_min_width(format_opt, str_arg_after_precision);
		free(str_arg_after_precision);
	}
	ft_putstr_fd(final_str_arg, 1);
	(*number_chars_printed) += ft_strlen(final_str_arg);
	free(final_str_arg);
}
