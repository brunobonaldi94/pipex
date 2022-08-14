/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 01:07:42 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/19 01:35:46 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrchr_pos(const char *s, int c)
{
	int	s_len;

	if (!s)
		return (-1);
	s_len = (int)ft_strlen(s);
	while (s_len)
	{
		if (s[s_len] == (char)c)
			return (s_len);
		s_len--;
	}
	return (-1);
}
