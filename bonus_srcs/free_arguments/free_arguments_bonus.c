/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arguments_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:21:55 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/16 02:34:02 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_cmd(t_arguments *arguments)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (i < arguments->number_commands)
	{
		j = 0;
		while (arguments->commands[i].cmd_to_parse[j])
		{
			free(arguments->commands[i].cmd_to_parse[j]);
			j++;
		}
		free(arguments->commands[i].argv);
		free(arguments->commands[i].cmd_to_parse);
		free(arguments->commands[i].cmd);
		i++;
	}
}

void	free_args(t_arguments *arguments)
{
	free_cmd(arguments);
	free(arguments->commands);
	free(arguments->path);
}

void	free_pipex(t_arguments *arguments)
{
	free(arguments->fd_pipes);
	free(arguments->pids_fork);
	free_args(arguments);
}
