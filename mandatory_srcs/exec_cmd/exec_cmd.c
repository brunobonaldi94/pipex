/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:35:22 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/09 23:35:51 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_stdin_out(t_arguments *arguments)
{
	arguments->std_in = dup(STDIN_FILENO);
	arguments->std_out = dup(STDOUT_FILENO);
}

void	restore_stdin_out(t_arguments *arguments)
{
	dup2(arguments->std_in, STDIN_FILENO);
	close(arguments->std_in);
	dup2(arguments->std_out, STDOUT_FILENO);
	close(arguments->std_out);
}

void	exec_each_cmd(t_arguments *arguments, int process_index)
{
	int err;

	if (arguments->commands[process_index].cmd == NULL)
	{
		restore_stdin_out(arguments);
		print_custom_arg_error_exit(arguments->commands[process_index].argv[0],
			COMMAND_NOT_FOUND_ERROR_CODE, COMMAND_NOT_FOUND_ERROR_MSG);
	}
	err = execve(arguments->commands[process_index].cmd,
	 	arguments->commands[process_index].argv, arguments->envp);
	if (err == ERROR_CODE_FUNCTION) 
	{
		restore_stdin_out(arguments);
		perror_with_color(arguments->commands[process_index].argv[0]);
		exit(errno);
	}
}

void	exec_commands(t_arguments *arguments, int process_index)
{
	dup_stdin_out(arguments);
	if (process_index == 0)
	{
		close_read_pipe(arguments);
		arguments->input_file.fd = open_infile(arguments);
		dup2(arguments->input_file.fd, STDIN_FILENO);
		close_input(arguments);
		dup2(arguments->fd_pipes[0].fd[WRITE_FD], STDOUT_FILENO);
		close_write_pipe(arguments);
	}
	else 
	{
		close_write_pipe(arguments);
		dup2(arguments->fd_pipes[0].fd[READ_FD], STDIN_FILENO);
		close_read_pipe(arguments);
		arguments->output_file.fd = open_output(arguments);
		dup2(arguments->output_file.fd, STDOUT_FILENO);
		close_output(arguments);
	}
	exec_each_cmd(arguments, process_index);
}
