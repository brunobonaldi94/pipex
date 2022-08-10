/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:54:58 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/09 23:12:15 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_cmd(t_cmd *cmd)
{
	cmd->cmd_to_parse = NULL;
	cmd->cmd = NULL;
	cmd->argv = NULL;
}

void	init_std(t_arguments *arguments)
{
	arguments->std_in = STDIN_FILENO;
	arguments->std_out = STDOUT_FILENO;
}

void	init_args_main(t_arguments *arguments)
{
	arguments->argc = 0;
	arguments->argv = NULL;
	arguments->envp = NULL;
}

void	init_pipe_args(t_arguments *arguments)
{
	arguments->fd_pipes = NULL;
	arguments->number_commands = 0;
	arguments->pids_fork = 1;
	arguments->commands = NULL;
	arguments->input_file.file_name = NULL;
	arguments->input_file.fd = 0;
	arguments->output_file.file_name = NULL;
	arguments->path = NULL;
	arguments->output_file.fd = 0;
}

void	init_args(t_arguments *arguments)
{
	init_args_main(arguments);
	init_pipe_args(arguments);
	arguments->exit_code = 0;
}

void	load_args(int argc, char *argv[], char *envp[], t_arguments *arguments)
{
	init_args(arguments);
	arguments->argc = argc;
	arguments->argv = argv;
	arguments->envp = envp;
}

void	parse_cmd(t_cmd *cmd)
{
	int	i;
	
	i = 0;
	while (cmd->cmd_to_parse[i])
		++i;
	cmd->argv = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (cmd->cmd_to_parse[i])
	{
		cmd->argv[i] = cmd->cmd_to_parse[i];
		i++;
	}
	cmd->argv[i] = NULL;
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