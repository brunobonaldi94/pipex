/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:32:36 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/18 21:04:05 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_string;
	size_t	join_total_len;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join_total_len = s1_len + s2_len + 1;
	join_string = (char *)malloc(sizeof(char) * join_total_len);
	if (!join_string)
		return (NULL);
	ft_strlcpy(join_string, s1, join_total_len);
	ft_strlcat(join_string, s2, join_total_len);
	return (join_string);
}
