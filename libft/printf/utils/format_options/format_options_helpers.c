/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_options_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:18:33 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/20 22:01:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_last_flag(char c, t_format_opt *format_opt)
{
	size_t	buffer_size;
	size_t	index;

	index = 0;
	buffer_size = sizeof(format_opt->flags);
	while (format_opt->flags[index])
	{
		if (format_opt->flags[index] == c)
			return ;
		index++;
	}
	if (index != buffer_size - 1)
		format_opt->flags[index] = c;
	format_opt->flags[buffer_size - 1] = '\0';
}

int	is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' '
		|| c == '#' || c == '0');
}

int	is_specifier(char c)
{
	return (c == 'c' || c == 's'
		|| c == 'p' || c == 'd'
		|| c == 'i' || c == 'u'
		|| c == 'x' || c == 'X'
		|| c == '%');
}

void	reset_pointer_and_set_property_default(const char **format_template,
	const char *start, t_format_opt **format_opt, char property_type)
{
	*format_template = start;
	if (property_type == 'w')
		(*format_opt)->width = -1;
	else if (property_type == 'p')
		(*format_opt)->precision = -1;
}

int	find_format_template(const char **format_template, char **format_start,
		int *numbers_bytes_printed, t_format_opt *format_opt)
{
	const char	*fmt_template;
	int			found;

	fmt_template = *format_template;
	found = 0;
	while (*fmt_template)
	{
		if (*fmt_template == '%')
		{
			*format_start = (char *)fmt_template;
			fmt_template++;
			found = 1;
			break ;
		}
		if (!format_opt || format_opt->is_valid)
			ft_putchar_fd(*fmt_template, 1);
		fmt_template++;
		(*numbers_bytes_printed) += 1;
	}
	*format_template = fmt_template;
	return (found);
}
