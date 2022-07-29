/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:59:50 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/29 02:49:46 by coder            ###   ########.fr       */
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

void	load_file(t_args *args)
{
	args->input_file.file_name = args->argv[1];
	args->input_file.fd = open(args->input_file.file_name, O_RDONLY);
	args->output_file.file_name = args->argv[args->argc - 1];
	args->output_file.fd = open(args->output_file.file_name, O_RDONLY);
	if (args->input_file.fd < 0)
		print_arg_error(args->input_file.file_name,
			ERROR_CODE, FILE_NOT_FOUND_ERROR_MSG);
	if (args->output_file.fd < 0)
		print_arg_error(args->output_file.file_name,
			ERROR_CODE, FILE_NOT_FOUND_ERROR_MSG);
}

void	load_args(int argc, char *argv[], char *envp[], t_args *args)
{
	args->argc = argc;
	args->argv = argv;
	args->envp = envp;
}

int	parse_args(t_args *args)
{
	if (args->argc <= 4)
		exit_with_message(ERROR_CODE, TOO_FEW_ARGUMENTS_ERROR_MSG);
	load_file(args);
	ft_printf("%d | %d", args->input_file.fd, args->output_file.fd);
	close(args->input_file.fd);
	close(args->output_file.fd);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_args	args;

	load_args(argc, argv, envp, &args);
	parse_args(&args);
	return (0);
}
