/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:35:22 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/17 20:27:12 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	int	err;

	if (arguments->commands[process_index].cmd == NULL)
	{
		restore_stdin_out(arguments);
		print_custom_arg_error_and_exit(arguments,
			arguments->commands[process_index].argv[0],
			COMMAND_NOT_FOUND_ERROR_CODE,
			COMMAND_NOT_FOUND_ERROR_MSG);
	}
	err = execve(arguments->commands[process_index].cmd,
			arguments->commands[process_index].argv, arguments->envp);
	if (err == ERROR_CODE_FUNCTION)
	{
		restore_stdin_out(arguments);
		perror_with_color(arguments,
			arguments->commands[process_index].argv[0]);
		exit(errno);
	}
}

void	exec_commands(t_arguments *arguments, int process_index)
{
	dup_stdin_out(arguments);
	if (process_index == 0)
		handle_fds_first_cmd(arguments, process_index);
	else if (process_index < arguments->number_commands - 1)
		handle_fds_middles_cmds(arguments, process_index);
	else
		handle_fds_last_cmd(arguments, process_index);
	exec_each_cmd(arguments, process_index);
}
