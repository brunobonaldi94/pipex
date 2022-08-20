/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:05:24 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/20 17:28:16 by bbonaldi         ###   ########.fr       */
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

	line_acc = ft_strdup("");
	while (TRUE)
	{
		line = get_next_line(STDIN_FILENO);
		if (here_doc_line_substring_handler(arguments, &line_acc, &line) >= 0)
			break ;
		line_acc = ft_strjoin_custom(line_acc, line);
		ft_ptr_free((void *)&line);
	}
	return (line_acc);
}

void	parse_and_write_here_doc(t_arguments *arguments, int fd_here_doc)
{
	char	*line_join;

	line_join = here_doc_line_accumulator(arguments);
	write(fd_here_doc, line_join, ft_strlen(line_join));
	free(line_join);
}

void	deal_fork_here_doc(t_arguments *arguments, int fd[2],
			pid_t pid_here_doc, int process_index)
{
	if (pid_here_doc == -1)
		print_arg_error_and_exit(arguments, FORK_ARG, EXIT_FAILURE);
	if (pid_here_doc == 0)
	{
		close(fd[READ_FD]);
		parse_and_write_here_doc(arguments, fd[WRITE_FD]);
		close(fd[WRITE_FD]);
		free_pipex(arguments);
		exit(SUCCESS_CODE);
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
