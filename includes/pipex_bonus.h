/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:07:26 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/20 17:28:00 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

# define TRUE 1
# define FALSE 0

# define ERROR_CODE 1
# define SUCCESS_CODE 0
# define ERROR_CODE_FUNCTION -1

# define READ_FD 0
# define WRITE_FD 1

# define STDIN 0
# define STDOUT 1
# define STDERROR 2

# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"

# define INDEX_COMMANDS_START 2
# define COMMANDS_OFFSET 3
# define MINIMUM_NUMBER_ARGS 4

# define PATH "PATH="
# define DEFAULT_PERMISSION 0000664

# define SPACE_CHAR ' '
# define SINGLE_QUOTE_CHAR '\''
# define DOUBLE_QUOTE_CHAR '"'
# define COMMA_CHAR ':' 
# define SLASH_STRING "/"
# define BACKSLASH_CHAR '\\'
# define SENTINEL_CHAR -28
# define HERE_DOC "here_doc"

# define PIPEX_NAME "pipex: "
# define TOO_FEW_ARGUMENTS_ERROR_MSG "Pipex must be run with at least \
'file1' 'cmd1' 'cmd2' 'file2' arguments"
# define TOO_MANY_ARGUMENTS_ERROR_MSG "Pipex must be run only with 4 args \
'file1' 'cmd1' 'cmd2' 'file2' arguments"
# define COMMAND_NOT_FOUND_ERROR_CODE 127
# define COMMAND_NOT_FOUND_ERROR_MSG "command not found"
# define FILE_NOT_FOUND_ERROR_MSG "no such file or directory!"
# define PIPE_ARG "Pipe"
# define PIPE_CREATION_ERROR_MSG "Error on creating pipe!"
# define FORK_ARG "Fork"
# define FORK_CREATION_ERROR_MSG "Error on initing fork!"
# define PERMISSION_DENIED_ERROR_CODE 126
# define PERMISSION_DENIED_ERROR_MSG "Permission denied"

# define FILE_DOES_NOT_EXIST -1
# define PERMISSION_NOT_ALLOWED 1
# define PERMISSION_OK 0

# define CLOSE_ALL -1

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

typedef struct s_here_doc
{
	int		is_here_doc;
	char	*delimiter;

}	t_here_doc;

typedef struct s_arguments
{
	int			argc;
	char		**argv;
	char		**envp;
	int			std_in;
	int			std_out;
	char		*path;
	t_pipes_fd	*fd_pipes;
	int			number_pipes;
	pid_t		*pids_fork;
	int			number_commands;
	int			exit_code;
	int			index_commands_start;
	int			commands_offset_number;
	t_cmd		*commands;
	t_file		input_file;
	t_file		output_file;
	t_here_doc	here_doc;
}	t_arguments;

//PARSE_ARGS_FUNCTIONS
void	parse_commands(t_arguments *arguments);
int		parse_args(t_arguments *arguments);
void	load_args(int argc, char *argv[], char *envp[],
			t_arguments *arguments);
void	parse_cmd(t_cmd *cmd);
void	check_command_bin_with_no_path(t_arguments *arguments,
			int command_index);
void	init_args(t_arguments *arguments);
void	init_cmd(t_cmd *cmd);
char	**tokenizer(t_arguments *arguments, int argv_index);
//HERE_DOC
int		check_here_doc_argument(t_arguments *arguments);
void	parse_here_doc(t_arguments *arguments, int fd_here_doc);
void	pipe_here_doc(t_arguments *arguments, int process_index);
int		here_doc_line_substring_handler(t_arguments *arguments,
			char **line_acc, char **line);
//ERROR_HANDLER_FUNCTIONS
void	exit_with_message(int status_code, char *message);
void	print_arg_error_and_exit(t_arguments *arguments, char *arg,
			int status_code);
void	print_custom_arg_error_and_exit(t_arguments *arguments, char *arg,
			int status_code, char *message);
void	perror_with_color(t_arguments *arguments, char *arg);
void	perror_formmated(t_arguments *arguments, char *message);
//CLOSE FDS
void	close_read_pipe(t_arguments *arguments, int pipe_index);
void	close_input(t_arguments *arguments);
void	close_output(t_arguments *arguments);
void	close_write_pipe(t_arguments *arguments, int pipe_index);
void	close_pipes(t_arguments *arguments, int keep_read_pipe_index,
			int keep_write_pipe_index);
void	close_input_output(t_arguments *arguments);
void	close_all_fds(t_arguments *arguments);
//PROCESSES
void	exec_commands(t_arguments *arguments, int process_index);
void	handle_fds_first_cmd(t_arguments *arguments, int process_index);
void	handle_fds_middles_cmds(t_arguments *arguments, int process_index);
void	handle_fds_last_cmd(t_arguments *arguments, int process_index);
//FILES
int		open_infile(t_arguments *arguments);
int		open_output(t_arguments *arguments);
//FREE
void	free_cmd(t_arguments *arguments);
void	free_args(t_arguments *arguments);
void	free_pipex(t_arguments *arguments);
#endif