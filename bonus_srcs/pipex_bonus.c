/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:59:50 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/15 23:38:16 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	get_exit_code(t_arguments *arguments)
{
	int	i;

	arguments->exit_code = 0;
	i = 0;
	while (i < arguments->number_commands)
	{
		waitpid(arguments->pids_fork, &arguments->exit_code, 0);
		if (WIFEXITED(arguments->exit_code))
		{
			arguments->exit_code = WEXITSTATUS(arguments->exit_code);
			return (arguments->exit_code);
		}
		i++;
	}
	return (arguments->exit_code);
}

void	fork_childs(t_arguments *arguments)
{
	int	i;

	i = 0;
	while (i < arguments->number_commands)
	{
		if (arguments->pids_fork != 0)
			arguments->pids_fork = fork();
		if (arguments->pids_fork == -1)
			print_arg_error_and_exit(arguments, FORK_ARG, EXIT_FAILURE);
		if (arguments->pids_fork == 0)
			exec_commands(arguments, i);
		i++;
	}
}

void	create_pipes(t_arguments *arguments)
{
	arguments->number_pipes = 0;
	arguments->fd_pipes = (t_pipes_fd *)malloc(sizeof(t_pipes_fd)
			* arguments->number_commands - 1);
	while (arguments->number_pipes < arguments->number_commands - 1)
	{
		if (pipe(arguments->fd_pipes[arguments->number_pipes].fd)
			== ERROR_CODE_FUNCTION)
		{
			close_pipes(arguments, CLOSE_ALL, CLOSE_ALL);
			print_arg_error_and_exit(arguments, PIPE_ARG, EXIT_FAILURE);
		}
		arguments->number_pipes++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arguments	arguments;

	load_args(argc, argv, envp, &arguments);
	parse_args(&arguments);
	create_pipes(&arguments);
	fork_childs(&arguments);
	close_pipes(&arguments, CLOSE_ALL, CLOSE_ALL);
	free_pipex(&arguments);
	return (get_exit_code(&arguments));
}
