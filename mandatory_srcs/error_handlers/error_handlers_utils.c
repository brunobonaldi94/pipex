/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:00:43 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/09 23:36:14 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_with_message(int status_code, char *message)
{
	if (status_code == SUCESS_CODE)
		ft_printf(GREEN"%s\n",message);
	else
		ft_printf(RED"%s\n",message);		
	exit(status_code);
}


void	print_custom_arg_error_exit(char *arg, int status_code, char *message)
{
		ft_printf("%s: ", arg);
		exit_with_message(status_code, message);
}

void	print_arg_error_exit(char *arg, int status_code, char *message)
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

void	close_read_pipe(t_arguments *arguments)
{
 	close(arguments->fd_pipes[0].fd[READ_FD]);
}

void	close_write_pipe(t_arguments *arguments)
{
	close(arguments->fd_pipes[0].fd[WRITE_FD]);
}

void	close_pipes(t_arguments *arguments)
{
	close_read_pipe(arguments);
	close_write_pipe(arguments);
}

void	close_input(t_arguments *arguments)
{
	close(arguments->input_file.fd);
}


void	close_output(t_arguments *arguments)
{
	close(arguments->output_file.fd);
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