/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:35:22 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/06 15:39:18 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_child_process(t_arguments *arguments, int process_index)
{
	if (process_index == 0)
	{
		dup2(arguments->input_file.fd, STDIN);
		dup2(arguments->fd_pipes[0].fd[WRITE_FD], STDOUT);
	}
	else 
	{
		dup2(arguments->fd_pipes[0].fd[READ_FD], STDIN);
		dup2(arguments->output_file.fd, STDOUT);
	}
	close(arguments->input_file.fd);
	close(arguments->fd_pipes[0].fd[WRITE_FD]);
	close(arguments->fd_pipes[0].fd[READ_FD]);
	close(arguments->output_file.fd);
	int err = execve(arguments->commands[process_index].cmd, 
	 	arguments->commands[process_index].argv, arguments->envp);
	if (err == ERROR_CODE_FUNCTION) 
	{
		perror(arguments->commands[process_index].argv[0]);
		exit(ERROR_CODE_FUNCTION);
	}
}
