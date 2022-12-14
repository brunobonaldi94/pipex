/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:38:28 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/18 23:18:21 by bbonaldi         ###   ########.fr       */
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
	arguments->pids_fork = NULL;
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
