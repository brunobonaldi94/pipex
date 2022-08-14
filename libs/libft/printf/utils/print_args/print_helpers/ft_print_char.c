/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:55:31 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/20 22:01:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_null_byte_print(t_format_opt *format_opt,
			size_t *arg_char_str_len)
{
	int	print_null_order;

	print_null_order = 0;
	if (format_opt->width > 1 && has_flag(format_opt, '-'))
			print_null_order = 1;
	else
			print_null_order = 2;
	(*arg_char_str_len) += 1;
	format_opt->width -= 1;
	return (print_null_order);
}

void	manage_print_order(char *arg_char_str_ptr, size_t arg_char_str_len,
			int *number_chars_printed, int should_print_null_byte)
{
	if (should_print_null_byte == 1)
		ft_putchar_fd('\0', 1);
	arg_char_str_len += ft_strlen(arg_char_str_ptr);
	ft_putstr_fd(arg_char_str_ptr, 1);
	if (should_print_null_byte == 2)
		ft_putchar_fd('\0', 1);
	free(arg_char_str_ptr);
	(*number_chars_printed) += arg_char_str_len;
}

void	ft_print_char(va_list list_args, int *number_chars_printed,
			t_format_opt *format_opt)
{
	char	arg_char_str[2];
	char	*arg_char_str_ptr;
	int		should_print_null_byte;
	size_t	arg_char_str_len;

	arg_char_str[0] = va_arg(list_args, int);
	arg_char_str[1] = '\0';
	arg_char_str_len = 0;
	should_print_null_byte = 0;
	if (arg_char_str[0] == '\0')
		should_print_null_byte = manage_null_byte_print(format_opt,
				&arg_char_str_len);
	arg_char_str_ptr = ft_min_width(format_opt, arg_char_str);
	manage_print_order(arg_char_str_ptr, arg_char_str_len,
		number_chars_printed, should_print_null_byte);
}
