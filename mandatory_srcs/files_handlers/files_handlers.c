/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:35:07 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/09 22:48:08 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(t_arguments *arguments)
{
	int	fd;

	fd = open(arguments->input_file.file_name, O_RDONLY);
	if (fd < 0)
		print_arg_error_exit(arguments->input_file.file_name, EXIT_FAILURE,
			FILE_NOT_FOUND_ERROR_MSG);
	return fd;
}

int	open_output(t_arguments *arguments)
{
	int	fd;

	fd = open(arguments->output_file.file_name,
		O_TRUNC | O_CREAT | O_RDWR, DEFAULT_PERMISSION);
	if (fd < 0)
		print_arg_error_exit(arguments->output_file.file_name, EXIT_FAILURE,
			FILE_NOT_FOUND_ERROR_MSG);
	return fd;
}