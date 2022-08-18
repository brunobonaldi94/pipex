/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 20:21:14 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/17 23:05:17 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_fds_first_cmd(t_arguments *arguments, int process_index)
{
	if (arguments->here_doc.is_here_doc == TRUE)
	{
		create_here_doc(arguments, process_index);
		return ;
	}
	close_pipes(arguments, CLOSE_ALL, process_index);
	arguments->input_file.fd = open_infile(arguments);
	dup2(arguments->input_file.fd, STDIN_FILENO);
	close(arguments->input_file.fd);
	dup2(arguments->fd_pipes[process_index].fd[WRITE_FD], STDOUT_FILENO);
	close(arguments->fd_pipes[process_index].fd[WRITE_FD]);
}

void	handle_fds_middles_cmds(t_arguments *arguments, int process_index)
{
	close_pipes(arguments, process_index - 1, process_index);
	dup2(arguments->fd_pipes[process_index - 1].fd[READ_FD], STDIN_FILENO);
	close(arguments->fd_pipes[process_index - 1].fd[READ_FD]);
	dup2(arguments->fd_pipes[process_index].fd[WRITE_FD], STDOUT_FILENO);
	close(arguments->fd_pipes[process_index].fd[WRITE_FD]);
}

void	handle_fds_last_cmd(t_arguments *arguments, int process_index)
{
	close_pipes(arguments, process_index - 1, CLOSE_ALL);
	dup2(arguments->fd_pipes[process_index - 1].fd[READ_FD], STDIN_FILENO);
	close(arguments->fd_pipes[process_index - 1].fd[READ_FD]);
	arguments->output_file.fd = open_output(arguments);
	dup2(arguments->output_file.fd, STDOUT_FILENO);
	close(arguments->output_file.fd);
}
