/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:05:24 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/17 23:43:27 by bbonaldi         ###   ########.fr       */
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

void	parse_here_doc(t_arguments *arguments, int fd_here_doc)
{
	char	*line;
	char	*line_join;
	char	*subs;
	int		pos;

	line_join = ft_strdup("");
	line = NULL;
	while (TRUE)
	{
		line = get_next_line(STDIN_FILENO);
		pos = ft_strnstr_pos(line, arguments->here_doc.delimiter, ft_strlen(line));
		if (pos >= 0)
		{
			subs = ft_substr(line, 0, pos);
			free(line);
			line_join = ft_strjoin_custom(line_join, subs);
			free(subs);
			break ;
		}
		line_join = ft_strjoin_custom(line_join, line);
		free(line);
		line = NULL;
	}
	write(fd_here_doc, line_join, ft_strlen(line_join));
	free(line_join);
	exit(SUCCESS_CODE);
}

void	create_here_doc(t_arguments *arguments, int process_index)
{
	int	fd[2];
	pid_t	pid_here_doc;

	if(pipe(fd) < 0)
	{
		close_pipes(arguments, CLOSE_ALL, CLOSE_ALL);
		print_arg_error_and_exit(arguments, PIPE_ARG, EXIT_FAILURE);
	}
	pid_here_doc = fork();
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