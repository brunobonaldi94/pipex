/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:27:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/21 12:28:46 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	const char	*nptr_ptr;
	int			sign_result;
	int			result;

	nptr_ptr = nptr;
	result = 0;
	sign_result = 1;
	while (ft_isascii(*nptr_ptr) == 2)
		nptr_ptr++;
	if (*nptr_ptr == '+' || *nptr_ptr == '-')
	{
		if (*nptr_ptr == '-')
			sign_result *= -1;
		nptr_ptr++;
	}
	while (ft_isdigit(*nptr_ptr))
	{
		result = (result * 10) + (*nptr_ptr - '0');
		nptr_ptr++;
	}
	return (result * sign_result);
}
