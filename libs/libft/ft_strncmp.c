/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:03:22 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/04/06 17:46:59 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	s1_char;
	unsigned char	s2_char;

	if (n == 0)
		return (0);
	while (*s1 && *s2 && (*s1 == *s2) && (n - 1))
	{
		s1++;
		s2++;
		n--;
	}
	s1_char = (unsigned char)*s1;
	s2_char = (unsigned char)*s2;
	return (s1_char - s2_char);
}
