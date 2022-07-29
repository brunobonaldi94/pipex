/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:07:26 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/29 02:41:50 by coder            ###   ########.fr       */
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

# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define BLACK "\033[0;30m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define TOO_FEW_ARGUMENTS_ERROR_MSG "Pipex must be run with at least \
'file1' 'cmd1' 'cmd2' 'file2' arguments"
# define FILE_NOT_FOUND_ERROR_MSG "File does not exist!"

typedef struct s_file
{
	int		fd;
	char	*file_name;
}	t_file;

typedef struct s_args
{
	int		argc;
	char	**argv;
	char	**envp;
	t_file	input_file;
	char	**commands;
	t_file	output_file;
}	t_args;

#endif