/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_options_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 04:09:47 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/20 21:57:16 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_format_flag(const char **format_template, t_format_opt **format_opt)
{
	const char	*flag;
	const char	*start;
	int			found;

	found = 0;
	flag = *format_template;
	start = *format_template;
	while (*flag && *flag != '%')
	{
		found = 0;
		if (is_specifier(*flag) || !is_flag(*flag))
			break ;
		if (is_flag(*flag))
		{
			add_last_flag(*flag, *format_opt);
			found = 1;
		}
		flag++;
	}
	if (found == 0 || !*flag || *flag == '%')
		reset_pointer_and_set_property_default(format_template, start,
			format_opt, 'f');
	else
		*format_template = flag;
	return (found);
}

int	add_format_precision(const char **format_template,
	t_format_opt **format_opt)
{
	const char	*precision;
	const char	*start;
	int			found;

	precision = *format_template;
	start = *format_template;
	found = 0;
	while (*precision && *precision != '%')
	{
		if (is_specifier(*precision))
			break ;
		if (*precision == '.')
		{
			(*format_opt)->precision = ft_atoi(++precision);
			found = 1;
			break ;
		}
		precision++;
	}
	if (found == 0 || !*precision || *precision == '%')
		reset_pointer_and_set_property_default(format_template, start,
			format_opt, 'p');
	else
		*format_template = precision;
	return (found);
}

int	add_format_specifier(const char **format_template,
	t_format_opt **format_opt)
{
	const char	*specifier;
	int			found;

	specifier = *format_template;
	found = 0;
	while (*specifier)
	{
		if (is_specifier(*specifier))
		{
			(*format_opt)->specifier = *specifier;
			specifier++;
			found = 1;
			break ;
		}
		if (!is_valid_format(specifier, format_opt))
		{
			found = (*format_opt)->is_valid;
			return (found);
		}
		specifier++;
	}
	if (found == 0)
		(*format_opt)->is_valid = 0;
	*format_template = specifier;
	return (found);
}

int	add_format_width(const char **format_template, t_format_opt **format_opt)
{
	const char	*width;
	const char	*start;
	int			found;

	width = *format_template;
	start = *format_template;
	found = 0;
	while (*width && *width != '%')
	{
		if (*width == '.')
			break ;
		if (ft_isdigit(*width))
		{
			(*format_opt)->width = ft_atoi(width);
			found = 1;
			break ;
		}
		width++;
	}
	if (found == 0)
		reset_pointer_and_set_property_default(format_template, start,
			format_opt, 'w');
	else
		*format_template = width;
	return (found);
}

void	add_format_template_start(const char *format_start,
			t_format_opt **format_opt)
{
	const char	*found_percentage;
	size_t		format_len;

	found_percentage = ft_strchr(format_start, '%');
	if (!found_percentage)
		found_percentage = format_start + ft_strlen(format_start);
	format_len = found_percentage - (--format_start);
	(*format_opt)->format_template = ft_substr(format_start, 0, format_len);
}
