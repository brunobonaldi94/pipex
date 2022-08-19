/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 20:21:14 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/18 23:11:25 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_fds_first_cmd(t_arguments *arguments)
{
	close_read_pipe(arguments);
	arguments->input_file.fd = open_infile(arguments);
	dup2(arguments->input_file.fd, STDIN_FILENO);
	close_input(arguments);
	dup2(arguments->fd_pipes[0].fd[WRITE_FD], STDOUT_FILENO);
	close_write_pipe(arguments);
}

void	handle_fds_last_cmd(t_arguments *arguments)
{
	close_write_pipe(arguments);
	dup2(arguments->fd_pipes[0].fd[READ_FD], STDIN_FILENO);
	close_read_pipe(arguments);
	arguments->output_file.fd = open_output(arguments);
	dup2(arguments->output_file.fd, STDOUT_FILENO);
	close_output(arguments);
}
