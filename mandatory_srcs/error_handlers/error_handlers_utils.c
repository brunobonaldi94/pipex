/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:00:43 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/08 22:58:57 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_with_message(int status_code, char *message)
{
	if (status_code == ERROR_CODE)
		ft_printf(RED"%s\n",message);
	else
		ft_printf(GREEN"%s\n",message);
	exit(status_code);
}

void	print_arg_error(char *arg, int status_code, char *message)
{
		perror(arg);
		exit_with_message(status_code, message);
}

void	perror_with_color(char *arg)
{
	ft_printf(RED"%s", "");
	perror(arg);
	ft_printf(RESET"%s", "");
}

void	close_pipes(t_arguments *arguments)
{
	close(arguments->fd_pipes[0].fd[WRITE_FD]);
	close(arguments->input_file.fd);
	close(arguments->fd_pipes[0].fd[WRITE_FD]);
	close(arguments->output_file.fd);
}
