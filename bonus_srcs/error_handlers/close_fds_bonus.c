/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:16:21 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/20 11:29:30 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_pipes(t_arguments *arguments, int keep_read_pipe_index,
			int keep_write_pipe_index)
{
	int	pipe_index;

	pipe_index = 0;
	while (pipe_index < arguments->number_pipes)
	{
		if (pipe_index != keep_read_pipe_index)
			close_read_pipe(arguments, pipe_index);
		if (pipe_index != keep_write_pipe_index)
			close_write_pipe(arguments, pipe_index);
		pipe_index++;
	}
}

void	close_input_output(t_arguments *arguments)
{
	close_input(arguments);
	close_output(arguments);
}

void	close_all_fds(t_arguments *arguments)
{
	close_input_output(arguments);
	close_pipes(arguments, CLOSE_ALL, CLOSE_ALL);
}
