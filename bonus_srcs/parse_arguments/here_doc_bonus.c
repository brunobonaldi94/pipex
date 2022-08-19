/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:05:24 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/18 21:59:14 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_here_doc_argument(t_arguments *arguments)
{
	int	has_here_doc;

	has_here_doc = FALSE;
	if (ft_strncmp(arguments->argv[1], HERE_DOC, ft_strlen(HERE_DOC))
		== SUCCESS_CODE)
	{
		has_here_doc = TRUE;
		arguments->here_doc.delimiter = arguments->argv[2];
		arguments->index_commands_start++;
		arguments->commands_offset_number++;
	}
	return (has_here_doc);
}

char	*here_doc_line_accumulator(t_arguments *arguments)
{
	char	*line;
	char	*line_acc;
	char	*substring_until_delimiter;
	int		pos;

	line_acc = ft_strdup("");
	while (TRUE)
	{
		line = get_next_line(STDIN_FILENO);
		pos = ft_strnstr_pos(line, arguments->here_doc.delimiter,
				ft_strlen(line));
		if (pos >= 0)
		{
			substring_until_delimiter = ft_substr(line, 0, pos);
			free(line);
			line_acc = ft_strjoin_custom(line_acc, substring_until_delimiter);
			free(substring_until_delimiter);
			break ;
		}
		line_acc = ft_strjoin_custom(line_acc, line);
		free(line);
		line = NULL;
	}
	return (line_acc);
}

void	parse_here_doc(t_arguments *arguments, int fd_here_doc)
{
	char	*line_join;

	line_join = here_doc_line_accumulator(arguments);
	write(fd_here_doc, line_join, ft_strlen(line_join));
	free(line_join);
	exit(SUCCESS_CODE);
}

void	deal_fork_here_doc(t_arguments *arguments, int fd[2],
			pid_t pid_here_doc, int process_index)
{
	if (pid_here_doc == -1)
		print_arg_error_and_exit(arguments, FORK_ARG, EXIT_FAILURE);
	if (pid_here_doc == 0)
	{
		close(fd[READ_FD]);
		parse_here_doc(arguments, fd[WRITE_FD]);
		close(fd[WRITE_FD]);
	}
	else
	{
		close(fd[WRITE_FD]);
		dup2(fd[READ_FD], STDIN_FILENO);
		close(fd[READ_FD]);
		dup2(arguments->fd_pipes[process_index].fd[WRITE_FD], STDOUT_FILENO);
		close_pipes(arguments, CLOSE_ALL, CLOSE_ALL);
		wait(NULL);
	}
}

void	pipe_here_doc(t_arguments *arguments, int process_index)
{
	int		fd[2];
	pid_t	pid_here_doc;

	if (pipe(fd) < 0)
	{
		close_pipes(arguments, CLOSE_ALL, CLOSE_ALL);
		print_arg_error_and_exit(arguments, PIPE_ARG, EXIT_FAILURE);
	}
	pid_here_doc = fork();
	deal_fork_here_doc(arguments, fd, pid_here_doc, process_index);
}
