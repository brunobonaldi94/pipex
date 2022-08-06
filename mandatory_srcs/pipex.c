/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:59:50 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/06 04:08:45 by bbonaldi         ###   ########.fr       */
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
	arguments->output_file.fd = open(arguments->output_file.file_name, O_RDWR|O_CREAT, 0664);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arguments	arguments;
	pid_t	pid1;

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
	pid1 = fork();

	if (pid1 == 0)
	{
		ft_printf("child=>in:%d|wr:%d\n",arguments.input_file.fd,arguments.fd_pipes[0].fd[WRITE_FD]);
		dup2(arguments.input_file.fd, STDIN);
		dup2(arguments.fd_pipes[0].fd[WRITE_FD], STDOUT);
		int err = execve("/usr/bin/grep", arguments.commands[0].argv, arguments.envp);
		if (err == ERROR_CODE_FUNCTION) 
		{

			perror("grep:");
			return ERROR_CODE;
		}
		close(arguments.fd_pipes[0].fd[READ_FD]);
		close(arguments.fd_pipes[0].fd[WRITE_FD]);
		close(arguments.input_file.fd);
		close(arguments.output_file.fd);
		free(arguments.fd_pipes);
	} else {
		int status;
		ft_printf("parent=>out:%d|read:%d\n",arguments.output_file.fd,arguments.fd_pipes[0].fd[READ_FD]);
		dup2(arguments.fd_pipes[0].fd[READ_FD], STDIN);
		dup2(arguments.output_file.fd, STDOUT);
		execve("/usr/bin/wc", arguments.commands[1].argv, arguments.envp);
		close(arguments.fd_pipes[0].fd[READ_FD]);
		close(arguments.fd_pipes[0].fd[WRITE_FD]);
		close(arguments.input_file.fd);
		close(arguments.output_file.fd);
		waitpid(pid1, &status, 0);
		if ( WIFEXITED(status) ) 
		{
        	int es = WEXITSTATUS(status);
			char *error = strerror(es);
        	ft_printf("Exit status was %d|%s\n", es, error);
		}
		free(arguments.fd_pipes);
	}
	return (0);
}
