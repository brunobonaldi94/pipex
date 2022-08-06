/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:00:43 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/06 00:01:01 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_with_message(int status_code, char *message)
{
	if (status_code == ERROR_CODE)
		ft_printf(RED"%s\n",message);
	else
		ft_printf(GREEN"%s\n",message);
	exit(status_code);
}

void	print_arg_error(char *arg, int status_code, char *message)
{
		ft_printf("arg: %s - ", arg);
		exit_with_message(status_code, message);
}
