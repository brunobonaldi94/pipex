/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:35:22 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/06 00:06:07 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_forks(t_arguments *arguments)
{
	int	i;

	i = 0;
    arguments->pids_fork = (pid_t *)malloc(sizeof(pid_t)
			* arguments->number_commands);
	while (i < arguments->number_commands)
	{
		pids_fork[i] = fork();
		if (pids_fork[i] == ERROR_CODE_FUNCTION)
		{
			exit_with_message(ERROR_CODE, FORK_CREATION_ERROR_MSG);
		}
		if (pids_fork[i] == 0) 
			return 0;
		
	}
}


void	exec_command(t_arguments *arguments)
{
 
}