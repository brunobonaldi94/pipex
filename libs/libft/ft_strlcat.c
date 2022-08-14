/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:25:43 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/07 21:08:08 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	index;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	index = 0;
	if (size <= dest_len || size == 0)
		return (src_len + size);
	while (src[index] && dest_len < (size - 1))
	{
		dst[dest_len] = src[index];
		dest_len++;
		index++;
	}
	dst[dest_len] = '\0';
	return (src_len + dest_len - index);
}
