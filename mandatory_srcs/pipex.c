/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:59:50 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/10 22:24:14 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			print_arg_error_and_exit(arguments,FORK_ARG, EXIT_FAILURE,
				FORK_CREATION_ERROR_MSG);
		if (arguments->pids_fork == 0)
			exec_commands(arguments, i);
		i++;
	}
}

void	free_pipex(t_arguments *arguments)
{
	free(arguments->fd_pipes);
	free_args(arguments);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arguments	arguments;

	load_args(argc, argv, envp, &arguments);
	parse_args(&arguments);
	arguments.fd_pipes = (t_pipes_fd *)malloc(sizeof(t_pipes_fd) * 1);
	if (pipe(arguments.fd_pipes[0].fd) == -1) 
	{
	 	free_pipex(&arguments);
		print_arg_error_and_exit(&arguments, PIPE_ARG, EXIT_FAILURE,
			PIPE_CREATION_ERROR_MSG);
	}
	fork_childs(&arguments);
	close_pipes(&arguments);
	free_pipex(&arguments);
	return (get_exit_code(&arguments));
}
