/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:35:22 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/06 01:59:39 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



void	exec_command(t_arguments *arguments, int i)
{
	ft_printf("fork%d\n", i);
 	if (i == 0)
	{
		ft_printf("%s--%s\n", arguments->commands[i].argv[0], arguments->commands[i].argv[1]);
		dup2(arguments->input_file.fd, STDIN);
		dup2(arguments->fd_pipes[0].fd[WRITE_FD], STDOUT);
		int err = execve("/usr/bin/grep", arguments->commands[i].argv, arguments->envp);
		close(arguments->fd_pipes[0].fd[READ_FD]);
		close(arguments->fd_pipes[0].fd[WRITE_FD]);
		if (err == ERROR_CODE_FUNCTION) 
		{
			perror("grep:");
			exit(ERROR_CODE_FUNCTION);
		}
	}
	else
	{
		ft_printf("%s--%s\n", arguments->commands[i].argv[0], arguments->commands[i].argv[1]);
		dup2(arguments->fd_pipes[0].fd[READ_FD], STDIN);
		dup2(arguments->output_file.fd, STDOUT);
		int err = execve("/usr/bin/wc", arguments->commands[i].argv, arguments->envp);
		close(arguments->fd_pipes[0].fd[READ_FD]);
		close(arguments->fd_pipes[0].fd[WRITE_FD]);
		if (err == ERROR_CODE_FUNCTION)
		{
			perror("wc:");
			exit(ERROR_CODE_FUNCTION);
		}
	}

}

void	init_child_processes(t_arguments *arguments)
{
	int	i;

	i = 0;
	arguments->pids_fork = (pid_t *)malloc(sizeof(pid_t) * 
		arguments->number_commands);
	while (i < arguments->number_commands)
	{
		arguments->pids_fork[i] = fork();
		if (arguments->pids_fork[i] == ERROR_CODE_FUNCTION)
			exit_with_message(ERROR_CODE, FORK_CREATION_ERROR_MSG);
		if (arguments->pids_fork[i] != 0)
			exit(SUCESS_CODE);
		i++;
	}
}
