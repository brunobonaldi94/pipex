/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:16:21 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/16 03:22:27 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_pipes(t_arguments *arguments)
{
	int	pipe_index;

	pipe_index = 0;
	while (pipe_index < arguments->number_pipes) 
	{
		close_read_pipe(arguments, pipe_index);
		close_write_pipe(arguments, pipe_index);
		pipe_index++;
	}
}

void	close_input_output(t_arguments *arguments)
{
	close(arguments->input_file.fd);
	close(arguments->output_file.fd);
}

void	close_all_fds(t_arguments *arguments)
{
	close(arguments->fd_pipes[0].fd[WRITE_FD]);
	close(arguments->input_file.fd);
	close(arguments->fd_pipes[0].fd[READ_FD]);
	close(arguments->output_file.fd);
}
