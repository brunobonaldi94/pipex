/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:15:27 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/18 21:14:43 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr_pos(const char *s1, const char *s2, size_t n)
{
	int		pos;
	size_t	s2_len;

	if (!*s2 || !s2 || !s1)
		return (-1);
	s2_len = ft_strlen(s2);
	pos = 0;
	while (*s1 && n >= s2_len)
	{
		if ((*s1 == *s2) && (ft_strncmp(s1, s2, s2_len) == 0))
			return (pos);
		s1++;
		n--;
		pos++;
	}
	return (-1);
}
