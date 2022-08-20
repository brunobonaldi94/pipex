/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds_II.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:16:21 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/20 11:44:22 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_read_pipe(t_arguments *arguments)
{
	if (arguments->fd_pipes[0].fd[READ_FD] < 0)
		return ;
	close(arguments->fd_pipes[0].fd[READ_FD]);
}

void	close_write_pipe(t_arguments *arguments)
{
	if (arguments->fd_pipes[0].fd[WRITE_FD] < 0)
		return ;
	close(arguments->fd_pipes[0].fd[WRITE_FD]);
}

void	close_input(t_arguments *arguments)
{
	if (arguments->input_file.fd < 0)
		return ;
	close(arguments->input_file.fd);
}

void	close_output(t_arguments *arguments)
{
	if (arguments->output_file.fd < 0)
		return ;
	close(arguments->output_file.fd);
}
