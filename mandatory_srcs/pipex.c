/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:59:50 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/06 15:43:48 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_infile(t_arguments *arguments)
{
	arguments->input_file.fd = open(arguments->input_file.file_name, O_RDONLY);
	if (arguments->input_file.fd < 0)
		print_arg_error(arguments->input_file.file_name,
			ERROR_CODE, FILE_NOT_FOUND_ERROR_MSG);
}

void	open_output(t_arguments *arguments)
{
	arguments->output_file.fd = open(arguments->output_file.file_name, O_TRUNC | O_CREAT | O_RDWR, 0000644);
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
	 	exit_with_message(ERROR_CODE, PIPE_CREATION_ERROR_MSG);
	}
	open_infile(&arguments);
	open_output(&arguments);
	int i = 0;
	while (i < arguments.number_commands)
	{
		if (arguments.pids_fork != 0)
			arguments.pids_fork = fork();
		if (arguments.pids_fork == 0)
			init_child_process(&arguments, i);
		i++;
	}	
	close(arguments.fd_pipes[0].fd[WRITE_FD]);
	close(arguments.input_file.fd);
	close(arguments.fd_pipes[0].fd[WRITE_FD]);
	close(arguments.output_file.fd);
	free(arguments.fd_pipes);
	free_args(&arguments);
	arguments.errors.error_code = 0;
	i = 0;
	while (i < arguments.number_commands) 
	{
		waitpid(arguments.pids_fork, &arguments.errors.error_code, 0);
		if (WIFEXITED(arguments.errors.error_code))
		{
			arguments.errors.error_code = WEXITSTATUS(arguments.errors.error_code);
			arguments.errors.message = strerror(arguments.errors.error_code);
			printf("Exit message was: %s\nExit status of the child was %d\n", 
				arguments.errors.message,
				arguments.errors.error_code);
		}
		i++;
	}
	return (0);
}
