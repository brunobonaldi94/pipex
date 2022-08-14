/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:57:24 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/07 23:57:52 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_uc;
	unsigned char	*dest_uc;

	src_uc = (unsigned char *)src;
	dest_uc = (unsigned char *)dest;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (dest > src)
	{
		while (n)
		{
			dest_uc[n - 1] = (unsigned char)src_uc[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
