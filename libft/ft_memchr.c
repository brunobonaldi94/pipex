/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:46:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/11 21:30:38 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_uc;
	size_t			index;

	s_uc = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (*s_uc == (unsigned char)c)
			return (s_uc);
		index++;
		s_uc++;
	}
	return (NULL);
}
