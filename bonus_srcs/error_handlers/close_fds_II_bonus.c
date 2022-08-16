/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds_II_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:16:21 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/16 03:10:54 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_read_pipe(t_arguments *arguments, int pipe_index)
{
	close(arguments->fd_pipes[pipe_index].fd[READ_FD]);
}

void	close_write_pipe(t_arguments *arguments, int pipe_index)
{
	close(arguments->fd_pipes[pipe_index].fd[WRITE_FD]);
}

void	close_input(t_arguments *arguments)
{
	close(arguments->input_file.fd);
}

void	close_output(t_arguments *arguments)
{
	close(arguments->output_file.fd);
}
