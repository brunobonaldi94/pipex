/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:35:22 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/08 23:25:31 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_each_cmd(t_arguments *arguments, int process_index)
{
	int err = execve(arguments->commands[process_index].cmd,
	 	arguments->commands[process_index].argv, arguments->envp);
	if (err == ERROR_CODE_FUNCTION) 
	{
		perror_with_color(arguments->commands[process_index].argv[0]);
		exit(EXIT_FAILURE);
	}
}

void	exec_commands(t_arguments *arguments, int process_index)
{
	if (process_index == 0)
	{
		if (arguments->input_file.fd < 0)
			exit(EXIT_FAILURE);
		dup2(arguments->input_file.fd, STDIN);
		dup2(arguments->fd_pipes[0].fd[WRITE_FD], STDOUT);
	}
	else 
	{
		dup2(arguments->fd_pipes[0].fd[READ_FD], STDIN);
		dup2(arguments->output_file.fd, STDOUT);
	}
	close_pipes(arguments);
	exec_each_cmd(arguments, process_index);
}
