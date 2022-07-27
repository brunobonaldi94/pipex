/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:51:37 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/08 19:10:44 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mem_s;
	size_t			index;

	index = 0;
	mem_s = (unsigned char *)s;
	while (index < n)
	{
		mem_s[index] = (unsigned char)c;
		index++;
	}
	return (s);
}
