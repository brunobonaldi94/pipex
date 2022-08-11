/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:39:18 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/10 23:08:57 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**tokenizer(t_arguments *arguments, int *argv_index)
{
	char	**split_arguments;
	// char	sentinel_value;
	// int	i;

	// i = 0;
	// sentinel_value = 255;
	// while (arguments->argv[(*argv_index)][i])
	// {
	// 	if (arguments->argv[(*argv_index)][i] == ' ' && i > 0 && i < )
	// 		arguments->argv[(*argv_index)][i] = sentinel_value;
	// 	i++;
	// }
	split_arguments = ft_split(arguments->argv[(*argv_index)], ' ');
	*argv_index += 1;
	return split_arguments;
}