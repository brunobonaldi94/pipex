/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:00:43 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/20 12:57:34 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exit_with_message(int status_code, char *message)
{
	ft_printf("%s\n", message);
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
	perror_formmated(arguments, arg);
	free_pipex(arguments);
}

void	print_arg_error_and_exit(t_arguments *arguments, char *arg,
			int status_code)
{
	perror_with_color(arguments, arg);
	exit(status_code);
}
