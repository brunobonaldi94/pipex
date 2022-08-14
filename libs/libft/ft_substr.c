/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:28:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/18 21:05:14 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	substring_len;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substring = (char *)ft_calloc(1, sizeof(char));
		return (substring);
	}
	if (len > s_len - start)
		len = s_len - start;
	substring_len = len + 1;
	substring = (char *)malloc(sizeof(char) * substring_len);
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, &s[start], substring_len);
	return (substring);
}
