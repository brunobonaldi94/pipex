/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:05:24 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/20 17:30:08 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	here_doc_line_substring_handler(t_arguments *arguments,
		char **line_acc, char **line)
{
	char	*substring_until_delimiter;
	int		position_delimiter;

	position_delimiter = ft_strnstr_pos(*line, arguments->here_doc.delimiter,
			ft_strlen(*line));
	if (position_delimiter >= 0)
	{
		substring_until_delimiter = ft_substr(*line, 0, position_delimiter);
		free(*line);
		*line_acc = ft_strjoin_custom(*line_acc, substring_until_delimiter);
		free(substring_until_delimiter);
	}
	return (position_delimiter);
}
