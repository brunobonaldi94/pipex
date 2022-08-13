/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:16:21 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/13 13:48:45 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_arguments *arguments)
{
	close_read_pipe(arguments);
	close_write_pipe(arguments);
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
