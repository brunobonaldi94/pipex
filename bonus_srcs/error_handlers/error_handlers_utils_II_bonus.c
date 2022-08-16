/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers_utils_II_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:00:43 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/16 02:34:35 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	perror_formmated(t_arguments *arguments, char *message)
{
	char	*pipex_with_comma;
	char	*message_concat_pipex;

	pipex_with_comma = ft_strjoin(arguments->argv[0] + 2, ": ");
	message_concat_pipex = ft_strjoin(pipex_with_comma, message);
	perror(message_concat_pipex);
	free(pipex_with_comma);
	free(message_concat_pipex);
}
