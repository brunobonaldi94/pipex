/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:07:26 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/10 22:08:20 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <string.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0

# define ERROR_CODE 1
# define SUCESS_CODE 0
# define ERROR_CODE_FUNCTION -1

# define READ_FD 0
# define WRITE_FD 1

# define STDIN 0
# define STDOUT 1
# define STDERROR 2

# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define BLACK "\033[0;30m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"

# define INDEX_COMMANDS_START 2
# define COMMANDS_OFFSET 3
# define MINIMUM_NUMBER_ARGS 4

# define TOO_FEW_ARGUMENTS_ERROR_MSG "Pipex must be run with at least \
'file1' 'cmd1' 'cmd2' 'file2' arguments"
# define FILE_NOT_FOUND_ERROR_MSG "File does not exist!"
# define PIPE_CREATION_ERROR_MSG "Error on creating pipe!"
# define FORK_CREATION_ERROR_MSG "Error on initing fork!"

typedef struct s_file
{
	int		fd;
	char	*file_name;
}	t_file;

typedef struct s_cmd
{
	char	**cmd_to_parse;
	char	*cmd;
	char	**argv;
}	t_cmd;

typedef struct s_pipes_fd
{
	int	fd[2];
}	t_pipes_fd;

typedef struct s_arguments
{
	int			argc;
	char		**argv;
	char		**envp;
	t_pipes_fd	*fd_pipes;
	pid_t		*pids_fork;
	int			number_commands;
	t_cmd		*commands;
	t_file		input_file;
	t_file		output_file;
}	t_arguments;

//PARSE_ARGS_FUNCTIONS
void	parse_commands(t_arguments *arguments);
int		parse_args(t_arguments *arguments);
void	load_args(int argc, char *argv[], char *envp[],
			t_arguments *arguments);
void	parse_cmd(t_cmd *cmd);
void	free_args(t_arguments *arguments);

void	init_args(t_arguments *arguments);
void	init_cmd(t_cmd *cmd);
//ERROR_HANDLER_FUNCTIONS
void	exit_with_message(int status_code, char *message);
void	print_arg_error(char *arg, int status_code, char *message);
//PROCESSES
void	init_child_processes(t_arguments *arguments);
void	exec_command(t_arguments *arguments, int i);
#endif