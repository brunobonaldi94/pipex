/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:39:18 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/16 02:46:44 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	keep_literal_string(char *current_argv, char scape_char,
			int inner_index)
{
	if (scape_char == SLASH_STRING[0]
		&& current_argv[inner_index] == scape_char)
	{
		current_argv[inner_index] = SENTINEL_CHAR;
		inner_index += 2;
	}
	else if (current_argv[inner_index] == scape_char)
	{
		current_argv[inner_index] = SENTINEL_CHAR;
		while (current_argv[inner_index]
			&& current_argv[inner_index] != scape_char)
			inner_index++;
		current_argv[inner_index] = SENTINEL_CHAR;
	}
	return (inner_index);
}

void	replace_delimiter_by_sentinel_char(t_arguments *arguments,
			char delimiter, int argv_index)
{
	int		i;

	i = 0;
	while (arguments->argv[argv_index][i])
	{
		i = keep_literal_string(arguments->argv[argv_index],
				SINGLE_QUOTE_CHAR, i);
		i = keep_literal_string(arguments->argv[argv_index],
				DOUBLE_QUOTE_CHAR, i);
		if (arguments->argv[argv_index][i] == delimiter)
			arguments->argv[argv_index][i] = SENTINEL_CHAR;
		i++;
	}
}

char	**tokenizer(t_arguments *arguments, int argv_index)
{
	char	**split_argument;

	replace_delimiter_by_sentinel_char(arguments, SPACE_CHAR, argv_index);
	split_argument = ft_split(arguments->argv[argv_index], SENTINEL_CHAR);
	return (split_argument);
}
