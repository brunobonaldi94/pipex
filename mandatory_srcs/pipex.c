/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:59:50 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/20 16:28:55 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_exit_code_and_free(t_arguments *arguments)
{
	int	i;

	i = 0;
	while (i < arguments->number_commands)
	{
		waitpid(arguments->pids_fork[i], &arguments->exit_code, 0);
		if (WIFEXITED(arguments->exit_code))
			arguments->exit_code = WEXITSTATUS(arguments->exit_code);
		i++;
	}
	free_pipex(arguments);
	return (arguments->exit_code);
}

void	fork_childs(t_arguments *arguments)
{
	int	i;

	i = 0;
	arguments->pids_fork = (pid_t *)malloc(sizeof(pid_t)
			* arguments->number_commands);
	ft_memset(arguments->pids_fork, 1, sizeof(pid_t)
		* arguments->number_commands);
	while (i < arguments->number_commands)
	{
		if (arguments->pids_fork[i] != 0)
			arguments->pids_fork[i] = fork();
		if (arguments->pids_fork[i] == -1)
			print_arg_error_and_exit(arguments, FORK_ARG, EXIT_FAILURE);
		if (arguments->pids_fork[i] == 0)
			exec_commands(arguments, i);
		i++;
	}
}

void	create_pipes(t_arguments *arguments)
{
	int	pipe_index;

	pipe_index = 0;
	arguments->fd_pipes = (t_pipes_fd *)malloc(sizeof(t_pipes_fd)
			* arguments->number_commands - 1);
	while (pipe_index < arguments->number_commands - 1)
	{
		if (pipe(arguments->fd_pipes[pipe_index].fd) == ERROR_CODE_FUNCTION)
			print_arg_error_and_exit(arguments, PIPE_ARG, EXIT_FAILURE);
		pipe_index++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arguments	arguments;

	load_args(argc, argv, envp, &arguments);
	parse_args(&arguments);
	create_pipes(&arguments);
	fork_childs(&arguments);
	close_pipes(&arguments);
	return (get_exit_code_and_free(&arguments));
}
