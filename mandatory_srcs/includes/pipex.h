/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:07:26 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/26 23:08:30 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0

# define ERROR_CODE 1
# define SUCESS_CODE 0

# define TOO_FEW_ARGUMENTS_ERROR_MSG "Pipex must be run with at least \
'file1' 'cmd1' 'cmd2' 'file2' arguments"

typedef struct s_file
{
	int		fd;
	char	*file_name;
}	t_file;

typedef struct s_args
{
	int		argc;
	t_file	input_file;
	char	**commands;
	t_file	output_file;
}	t_args;

#endif