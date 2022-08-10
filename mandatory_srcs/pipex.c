/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:59:50 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/09 23:07:09 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_child_exit_code(t_arguments *arguments)
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

int	main(int argc, char *argv[], char *envp[])
{
	t_arguments	arguments;
	int			i;

	load_args(argc, argv, envp, &arguments);
	parse_args(&arguments);
	arguments.fd_pipes = (t_pipes_fd *)malloc(sizeof(t_pipes_fd) * 1);
	if (pipe(arguments.fd_pipes[0].fd) == -1) 
	{
	 	free(arguments.fd_pipes);
		print_arg_error_exit(PIPE_ARG, EXIT_FAILURE, PIPE_CREATION_ERROR_MSG);
	}
	i = 0;
	while (i < arguments.number_commands)
	{
		if (arguments.pids_fork != 0)
			arguments.pids_fork = fork();
		if (arguments.pids_fork == -1)
			print_arg_error_exit(FORK_ARG, EXIT_FAILURE,
				FORK_CREATION_ERROR_MSG);
		if (arguments.pids_fork == 0)
			exec_commands(&arguments, i);
		i++;
	}
	close_pipes(&arguments);
	free(arguments.fd_pipes);
	free_args(&arguments);
	return (get_child_exit_code(&arguments));
}
