/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:53:13 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/26 23:15:43 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_each_format_template(const char *format,
	char *format_template_start, t_format_opt **printf_format,
	va_list lst_args)
{
	int				number_bytes_printed;
	t_format_opt	*current_printf_format;

	number_bytes_printed = 0;
	while (find_format_template(&format, &format_template_start,
			&number_bytes_printed, *printf_format))
	{
		current_printf_format = create_node();
		add_node_back(printf_format, current_printf_format);
		add_format_template_start(format, &current_printf_format);
		add_format_flag(&format, &current_printf_format);
		add_format_width(&format, &current_printf_format);
		add_format_precision(&format, &current_printf_format);
		add_format_specifier(&format, &current_printf_format);
		number_bytes_printed += print_args(&current_printf_format, lst_args);
	}
	return (number_bytes_printed);
}

int	ft_printf(const char *format, ...)
{
	va_list			lst_args;
	t_format_opt	*printf_format;
	int				number_bytes_printed;
	char			*format_template_start;

	if (!format)
		return (-1);
	va_start(lst_args, format);
	printf_format = NULL;
	format_template_start = NULL;
	number_bytes_printed = ft_process_each_format_template(format,
			format_template_start, &printf_format, lst_args);
	clear_list(&printf_format);
	va_end(lst_args);
	return (number_bytes_printed);
}
