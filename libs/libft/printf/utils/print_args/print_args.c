/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 02:23:18 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/20 22:01:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid_args(t_format_opt **format_opt)
{
	int	is_valid;

	is_valid = 1;
	if (!(*format_opt))
		is_valid = 0;
	if (!(*format_opt)->is_valid)
	{
		ft_putstr_fd((*format_opt)->format_template, 1);
		is_valid = 0;
	}
	return (is_valid);
}

int	print_args(t_format_opt **format_opt, va_list list_args)
{
	char	specifier;
	int		number_chars_printed;

	number_chars_printed = 0;
	if (!is_valid_args(format_opt))
		return (number_chars_printed);
	specifier = (*format_opt)->specifier;
	if (specifier == 'c')
		ft_print_char(list_args, &number_chars_printed, *format_opt);
	else if (specifier == 's')
		ft_print_str(list_args, &number_chars_printed, *format_opt);
	else if (specifier == 'd' || specifier == 'i')
		ft_print_int(list_args, &number_chars_printed, *format_opt);
	else if (specifier == 'u')
		ft_print_uint(list_args, specifier, &number_chars_printed,
			*format_opt);
	else if (specifier == 'p')
		ft_print_ptr(list_args, specifier, &number_chars_printed, *format_opt);
	else if (specifier == 'x' || specifier == 'X')
		ft_print_hex(list_args, specifier, &number_chars_printed, *format_opt);
	else if (specifier == '%')
		ft_print_percent(&number_chars_printed);
	return (number_chars_printed);
}
