/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:00:43 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/10 22:21:01 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_with_message(int status_code, char *message)
{
	if (status_code == SUCESS_CODE)
		ft_printf(GREEN"%s\n",message);
	else
		ft_printf(RED"%s\n",message);		
	exit(status_code);
}


void	print_custom_arg_error_and_exit(t_arguments *arguments, char *arg, 
				int status_code, char *message)
{
		ft_printf("%s: ", arg);
		free_pipex(arguments);
		exit_with_message(status_code, message);
}

void	print_arg_error_and_exit(t_arguments *arguments, char *arg, 
				int status_code, char *message)
{
		perror(arg);
		free_pipex(arguments);
		exit_with_message(status_code, message);
}

void	perror_with_color(char *arg)
{
	ft_printf(RED"%s", "");
	perror(arg);
	ft_printf(RESET"%s", "");
}
