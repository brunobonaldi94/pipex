/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:59:50 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/08 23:16:04 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_infile(t_arguments *arguments)
{
	arguments->input_file.fd = open(arguments->input_file.file_name, O_RDONLY);
	if (arguments->input_file.fd < 0)
		perror_with_color(arguments->input_file.file_name);		
}

void	open_output(t_arguments *arguments)
{
	arguments->output_file.fd = open(arguments->output_file.file_name,
		O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (arguments->output_file.fd < 0)
		perror_with_color(arguments->output_file.file_name);
}

int	get_child_exit_code(t_arguments *arguments)
{
	int	i;
	
	arguments->exit.exit_code = 0;
	i = 0;
	while (i < arguments->number_commands) 
	{
		waitpid(arguments->pids_fork, &arguments->exit.exit_code, 0);
		if (WIFEXITED(arguments->exit.exit_code))
		{
			arguments->exit.exit_code = WEXITSTATUS(arguments->exit.exit_code);
			arguments->exit.message = strerror(arguments->exit.exit_code);
			printf("Exit message was: %s\nExit status of the child was %d\n", 
				arguments->exit.message,
				arguments->exit.exit_code);
			return (arguments->exit.exit_code);
		}
		i++;
	}
	return (arguments->exit.exit_code);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arguments	arguments;

	load_args(argc, argv, envp, &arguments);
	parse_args(&arguments);
	arguments.fd_pipes = (t_pipes_fd *)malloc(sizeof(t_pipes_fd) * 1);
	if (pipe(arguments.fd_pipes[0].fd) == -1) 
	{
	 	free(arguments.fd_pipes);
	 	exit_with_message(EXIT_FAILURE, PIPE_CREATION_ERROR_MSG);
	}
	open_infile(&arguments);
	open_output(&arguments);
	int i = 0;
	while (i < arguments.number_commands)
	{
		if (arguments.pids_fork != 0)
			arguments.pids_fork = fork();
		if (arguments.pids_fork == -1)
			perror_with_color(FORK);
		if (arguments.pids_fork == 0)
			exec_commands(&arguments, i);
		i++;
	}
	close_pipes(&arguments);
	free(arguments.fd_pipes);
	free_args(&arguments);
	return (get_child_exit_code(&arguments));
}
