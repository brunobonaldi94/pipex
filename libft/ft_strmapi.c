/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:06:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/10 01:57:48 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	size_t	s_len;
	char	*strmapi;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	strmapi = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!strmapi)
		return (NULL);
	index = 0;
	while (s[index])
	{
		strmapi[index] = f(index, s[index]);
		index++;
	}
	strmapi[index] = 0;
	return (strmapi);
}
