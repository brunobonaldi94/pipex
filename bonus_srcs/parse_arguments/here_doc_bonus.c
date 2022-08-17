/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:05:24 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/17 03:33:15 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_here_doc_argument(t_arguments *arguments)
{
	int	has_here_doc;

	has_here_doc = FALSE;
	if (ft_strncmp(arguments->argv[1], HERE_DOC, ft_strlen(HERE_DOC)) == SUCESS_CODE)
	{
		has_here_doc = TRUE;
		arguments->here_doc.delimiter = arguments->argv[2];
		arguments->index_commands_start++;
		arguments->commands_offset_number++;
	}
	return (has_here_doc);
}