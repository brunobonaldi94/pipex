/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:00:28 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/19 12:54:17 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nbr_elements(int n)
{
	int	itoa_elements;

	itoa_elements = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		itoa_elements++;
		n /= 10;
	}
	return (itoa_elements);
}

static long int	change_sign(int n, int *sign)
{
	long int	nbr_copy;

	nbr_copy = n;
	if (nbr_copy < 0)
	{
		*sign = 1;
		nbr_copy *= -1;
	}
	return (nbr_copy);
}

char	*ft_itoa(int n)
{
	char			*itoa;
	int				itoa_elements;
	long int		n_copy;
	int				sign;

	sign = 0;
	itoa_elements = get_nbr_elements(n);
	n_copy = change_sign(n, &sign);
	itoa = (char *)malloc(sizeof(char) * (sign + itoa_elements + 1));
	if (!itoa)
		return (NULL);
	itoa[sign + itoa_elements] = '\0';
	if (sign == 1)
			itoa[0] = '-';
	while (itoa_elements)
	{
		itoa[sign + itoa_elements - 1] = (n_copy % 10) + '0';
		n_copy /= 10;
		itoa_elements--;
	}
	return (itoa);
}
