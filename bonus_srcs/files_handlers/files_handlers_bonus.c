/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_handlers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:35:07 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/18 00:03:39 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	set_write_flags(int is_here_doc)
{
	int	flags;

	if (is_here_doc == FALSE)
		flags = O_TRUNC | O_CREAT | O_RDWR;
	else
		flags = O_RDWR | O_APPEND | O_CREAT;
	return (flags);
}

int	check_access_file(char *file_name, int access_permissions)
{
	int	file_permission;

	file_permission = PERMISSION_OK;
	if (access(file_name, F_OK) != SUCCESS_CODE)
		file_permission = FILE_DOES_NOT_EXIST;
	else if (access(file_name, access_permissions) != SUCCESS_CODE)
		file_permission = PERMISSION_NOT_ALLOWED;
	return (file_permission);
}

int	open_infile(t_arguments *arguments)
{
	int	fd;
	int	file_permission;

	file_permission = check_access_file(arguments->input_file.file_name, R_OK);
	if (file_permission == PERMISSION_NOT_ALLOWED)
		print_arg_error_and_exit(arguments,
			arguments->input_file.file_name,
			PERMISSION_DENIED_ERROR_CODE);
	fd = open(arguments->input_file.file_name, O_RDONLY);
	if (fd < 0)
	{
		print_arg_error_and_exit(arguments,
			arguments->input_file.file_name,
			EXIT_FAILURE);
	}
	return (fd);
}

int	open_output(t_arguments *arguments)
{
	int	fd;
	int	file_permission;
	int	flags;

	file_permission = check_access_file(arguments->output_file.file_name,
			R_OK | W_OK);
	flags = set_write_flags(arguments->here_doc.is_here_doc);
	if (file_permission == PERMISSION_NOT_ALLOWED)
		print_arg_error_and_exit(arguments,
			arguments->output_file.file_name,
			EXIT_FAILURE);
	fd = open(arguments->output_file.file_name, flags, DEFAULT_PERMISSION);
	if (fd < 0)
	{
		print_arg_error_and_exit(arguments,
			arguments->output_file.file_name,
			EXIT_FAILURE);
	}
	return (fd);
}
