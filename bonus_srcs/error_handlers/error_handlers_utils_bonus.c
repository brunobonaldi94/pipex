/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:00:43 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/18 20:05:32 by bbonaldi         ###   ########.fr       */
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
	ft_printf("%s: %s: ", arguments->argv[0], arg);
	free_pipex(arguments);
	exit_with_message(status_code, message);
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
