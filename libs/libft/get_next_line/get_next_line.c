/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:31:43 by coder             #+#    #+#             */
/*   Updated: 2022/08/20 17:20:48 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*split_string_from_newline(char **line_acumulator,
	char **current_buffer, ssize_t newline_position)
{
	size_t	current_line_len;
	char	*line_with_newline;
	char	*current_line_after_nl;

	if (newline_position == -1)
		return (NULL);
	current_line_len = newline_position + 1;
	line_with_newline = (char *)malloc(sizeof(char) * current_line_len + 1);
	ft_strlcpy(line_with_newline, *line_acumulator, current_line_len + 1);
	current_line_after_nl = &(*line_acumulator)[current_line_len];
	ft_strlcpy(*current_buffer, current_line_after_nl,
		ft_strlen(current_line_after_nl) + 1);
	free(*line_acumulator);
	line_acumulator = NULL;
	return (line_with_newline);
}

char	*new_line_handler(char **current_buffer, char **line_acc,
	ssize_t newline_position)
{
	char	*line_with_newline;
	int		is_empty_string;
	int		has_newline;

	line_with_newline = NULL;
	has_newline = newline_position >= 0;
	if (has_newline)
		return (split_string_from_newline(line_acc,
				current_buffer, newline_position));
	is_empty_string = ft_strlen(*line_acc) > 0;
	if (is_empty_string)
	{
		line_with_newline = *line_acc;
		**current_buffer = '\0';
	}
	return (line_with_newline);
}

char	*find_next_line(int fd, char *current_buffer)
{
	char	*line_with_newline;
	char	*line_acc;
	ssize_t	newline_position;
	ssize_t	bytes_read;

	bytes_read = BUFFER_SIZE;
	line_acc = ft_strdup(current_buffer);
	while (!ft_strchr_custom(line_acc, NEW_LINE, &newline_position)
		&& bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, current_buffer, BUFFER_SIZE);
		current_buffer[bytes_read] = '\0';
		line_acc = ft_strjoin_custom(line_acc, current_buffer);
	}
	line_with_newline = new_line_handler(&current_buffer, &line_acc,
			newline_position);
	if (line_with_newline)
		return (line_with_newline);
	if (bytes_read == END_OF_FILE || bytes_read == FILE_NOT_FOUND || fd < 0)
	{
		free(line_acc);
		line_acc = NULL;
		return (NULL);
	}
	return (line_with_newline);
}

char	*get_next_line(int fd)
{
	static char	current_buffer[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0)
		return (NULL);
	return (find_next_line(fd, current_buffer));
}
