/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_zero_flag_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:45:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/20 22:01:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_padding	ft_justify_str(t_format_opt *format_opt, char *str_arg)
{
	size_t		index;
	t_padding	padding;

	index = 0;
	padding.len = 0;
	padding.char_symbol = ' ';
	while (format_opt->flags[index])
	{
		if (format_opt->flags[index] == '-')
		{
			padding.len = ft_strlen(str_arg);
			padding.char_symbol = ' ';
			break ;
		}
		if (format_opt->flags[index] == '0')
		{
			padding.len = 0;
			padding.char_symbol = '0';
			break ;
		}
		index++;
	}
	return (padding);
}
