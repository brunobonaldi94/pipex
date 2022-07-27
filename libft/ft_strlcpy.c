/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:10:14 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/11 23:12:13 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	qty_copied;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	qty_copied = 0;
	while (src[qty_copied] && (qty_copied < size - 1))
	{
		dst[qty_copied] = src[qty_copied];
		qty_copied++;
	}
	dst[qty_copied] = '\0';
	return (src_len);
}
