/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:00:43 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/20 13:13:12 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_with_message(int status_code, char *message)
{
	if (status_code == SUCCESS_CODE)
		ft_printf(GREEN"%s\n", message);
	else
		ft_printf(RED"%s\n", message);
	ft_printf(RESET);
	exit(status_code);
}

void	print_custom_arg_error_and_exit(t_arguments *arguments, char *arg,
				int status_code, char *message)
{
	int	fd_std_out;

	fd_std_out = dup(STDOUT_FILENO);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	ft_printf("%s: %s: %s\n", arguments->argv[0], arg, message);
	dup2(fd_std_out, STDOUT_FILENO);
	close(fd_std_out);
	free_pipex(arguments);
	exit(status_code);
}

void	perror_with_color(t_arguments *arguments, char *arg)
{
	ft_printf(RED);
	perror_formmated(arguments, arg);
	free_pipex(arguments);
	ft_printf(RESET);
}

void	print_arg_error_and_exit(t_arguments *arguments, char *arg,
			int status_code)
{
	perror_with_color(arguments, arg);
	exit(status_code);
}
