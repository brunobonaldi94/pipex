/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:50:31 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/07 21:09:12 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	index;

	index = 0;
	while (src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*duplicate_s;

	s_len = ft_strlen(s);
	duplicate_s = (char *)malloc(sizeof(*duplicate_s) * (s_len + 1));
	if (!duplicate_s)
		return (NULL);
	ft_strcpy(duplicate_s, s);
	return (duplicate_s);
}
