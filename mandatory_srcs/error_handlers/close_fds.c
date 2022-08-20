/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:16:21 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/20 11:25:24 by bbonaldi         ###   ########.fr       */
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
	close_input(arguments);
	close_output(arguments);
}

void	close_all_fds(t_arguments *arguments)
{
	close_input_output(arguments);
	close_pipes(arguments);
}
