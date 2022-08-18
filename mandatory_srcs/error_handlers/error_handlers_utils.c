/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:00:43 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/17 23:06:20 by bbonaldi         ###   ########.fr       */
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
	ft_printf("%s: %s: ", arguments->argv[0], arg);
	free_pipex(arguments);
	exit_with_message(status_code, message);
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
