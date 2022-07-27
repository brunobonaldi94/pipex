/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 06:20:48 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/22 20:41:56 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	has_flag(t_format_opt *format_opt, char flag)
{
	size_t	index;

	index = 0;
	while (format_opt->flags[index])
	{
		if (format_opt->flags[index] == flag)
			return (1);
		index++;
	}
	return (0);
}

void	remove_flag(t_format_opt *format_opt, char flag)
{
	size_t	index;
	size_t	temp_index;
	char	temp_format_opt_flag[6];

	index = 0;
	temp_index = 0;
	if (!has_flag(format_opt, flag))
		return ;
	while ((format_opt)->flags[index])
	{
		if ((format_opt)->flags[index] == flag)
		{
			index++;
			continue ;
		}
		temp_format_opt_flag[temp_index] = (format_opt)->flags[index];
		index++;
		temp_index++;
	}
	temp_format_opt_flag[temp_index] = '\0';
	ft_strlcpy((format_opt)->flags, temp_format_opt_flag, 6);
}

static int	get_nbr_elements(size_t n, int base)
{
	int	itoa_elements;

	itoa_elements = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		itoa_elements++;
		n /= base;
	}
	return (itoa_elements);
}

char	should_uppercase_hex(char specifier, char value)
{
	if (specifier == 'X')
		return (ft_toupper(value));
	return (value);
}

char	*ft_itoa_base(unsigned long int n, int base, char specifier)
{
	char		*itoa;
	int			itoa_elements;
	static char	hex_base[16] = "0123456789abcdef";

	itoa_elements = get_nbr_elements(n, base);
	itoa = (char *)malloc(sizeof(char) * (itoa_elements + 1));
	if (!itoa)
		return (NULL);
	itoa[itoa_elements] = '\0';
	while (itoa_elements)
	{
		itoa[itoa_elements - 1] = should_uppercase_hex(specifier,
				hex_base[n % base]);
		n /= base;
		itoa_elements--;
	}
	return (itoa);
}
