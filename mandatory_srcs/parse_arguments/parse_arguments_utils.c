/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:54:58 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/10 22:38:52 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	load_args(int argc, char *argv[], char *envp[], t_arguments *arguments)
{
	init_args(arguments);
	arguments->argc = argc;
	arguments->argv = argv;
	arguments->envp = envp;
}

void	parse_cmd(t_cmd *cmd)
{
	int	cmd_index;
	
	cmd_index = 0;
	while (cmd->cmd_to_parse[cmd_index])
		++cmd_index;
	cmd->argv = (char **)malloc(sizeof(char *) * (cmd_index + 1));
	cmd_index = 0;
	while (cmd->cmd_to_parse[cmd_index])
	{
		cmd->argv[cmd_index] = cmd->cmd_to_parse[cmd_index];
		cmd_index++;
	}
	cmd->argv[cmd_index] = NULL;
}


void free_cmd(t_arguments *arguments)
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