/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_options_invalid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:31:49 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/20 22:01:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid_format(const char *specifier, t_format_opt **format_opt)
{
	if (!is_specifier(*specifier) && !is_flag(*specifier)
		&& !ft_isdigit(*specifier) && *specifier != '.')
	{
		(*format_opt)->is_valid = 0;
	}
	return ((*format_opt)->is_valid);
}
