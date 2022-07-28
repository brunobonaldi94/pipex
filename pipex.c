/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:59:50 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/26 23:18:12 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_with_message(int status_code, char *message)
{
	ft_printf(message);
	exit(status_code);
}

// int	parse_args(int argc, char *argv[], t_args *args)
// {
// 	if (args->argc <= 1)
// 		exit_with_message(ERROR_CODE, TOO_FEW_ARGUMENTS_ERROR_MSG);
// 	ft_printf(argv[1]);
// 	return (0);
// }

int	load_args(int argc, char *argv[], t_args *args)
{
	if (args->argc <= 1)
		exit_with_message(ERROR_CODE, TOO_FEW_ARGUMENTS_ERROR_MSG);
	args->argc = argc;
	args->input_file.file_name = argv[1];
	args->input_file.fd = open(args->input_file.file_name, O_RDONLY);
	args->output_file.file_name = argv[argc - 1];
	args->output_file.fd = open(args->output_file.file_name, O_RDONLY);
	ft_printf("%d", argc);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_args	args;

	load_args(argc, argv, &args);
	return (0);
}
