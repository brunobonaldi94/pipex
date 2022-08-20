/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 03:13:32 by coder             #+#    #+#             */
/*   Updated: 2022/08/20 17:24:03 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_custom(const char *s, int c, ssize_t *newline_position)
{
	*newline_position = 0;
	while (*s != (char)c)
	{
		if (!*s)
		{
			*newline_position = -1;
			return (0);
		}
		s++;
		(*newline_position) += 1;
	}
	return (1);
}

char	*ft_strjoin_custom(char *s1, char *s2)
{
	char	*res;
	size_t	len;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len = s1_len + s2_len;
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = '\0';
	free(s1 - s1_len);
	s1 = NULL;
	return (res - len);
}
