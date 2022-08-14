/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:33:27 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/09 23:11:36 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index;
	size_t	s1_len;
	size_t	last_index;

	index = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[index]) && s1[index])
		index++;
	s1_len = ft_strlen(s1);
	while (ft_strchr(set, s1[s1_len]) && s1_len)
		s1_len--;
	last_index = s1_len - index + 1;
	return (ft_substr(s1, index, last_index));
}
