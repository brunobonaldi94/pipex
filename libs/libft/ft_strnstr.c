/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:15:27 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/06 17:46:45 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2_len;

	if (!*s2)
		return ((char *)(s1));
	s2_len = ft_strlen(s2);
	while (*s1 && n >= s2_len)
	{
		if ((*s1 == *s2) && (ft_strncmp(s1, s2, s2_len) == 0))
			return ((char *)(s1));
		s1++;
		n--;
	}
	return (NULL);
}
