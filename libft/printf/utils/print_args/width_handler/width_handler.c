/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:44:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/20 22:03:25 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*justify_string(t_format_opt *format_opt, char *str_arg,
					size_t	str_arg_len)
{
	size_t		width_difference;
	char		*min_width_str;
	t_padding	padding;
	int			width;

	width = format_opt->width;
	min_width_str = (char *)malloc(sizeof(char) * (width + 1));
	if (!min_width_str)
		return (NULL);
	padding = ft_justify_str(format_opt, str_arg);
	width_difference = width - str_arg_len;
	ft_memset(min_width_str + padding.len, padding.char_symbol,
		width_difference);
	if (padding.len)
			padding.len = width_difference;
	ft_memcpy(min_width_str + width_difference - padding.len,
		str_arg, str_arg_len);
	min_width_str[width] = '\0';
	return (min_width_str);
}

char	*ft_min_width(t_format_opt *format_opt, char *str_arg)
{
	int		width;
	char	*min_width_str;
	size_t	str_arg_len;

	width = format_opt->width;
	str_arg_len = ft_strlen(str_arg);
	if (width > (int)str_arg_len)
		min_width_str = justify_string(format_opt, str_arg, str_arg_len);
	else
		min_width_str = ft_strdup(str_arg);
	return (min_width_str);
}
