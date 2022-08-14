/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:28:57 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/15 02:57:59 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_nbr_elements(int n, int base)
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
