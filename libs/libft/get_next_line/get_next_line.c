/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:31:43 by coder             #+#    #+#             */
/*   Updated: 2022/06/24 23:59:20 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*split_string_from_newline(char **line_acumulator, t_gnl **gnl,
	ssize_t newline_position)
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
	ft_strlcpy((*gnl)->current_buffer, current_line_after_nl,
		ft_strlen(current_line_after_nl) + 1);
	free(*line_acumulator);
	line_acumulator = NULL;
	return (line_with_newline);
}

char	*new_line_handler(t_gnl **gnl, char **line_acc,
	ssize_t newline_position)
{
	char	*line_with_newline;
	int		is_empty_string;
	int		has_newline;

	line_with_newline = NULL;
	has_newline = newline_position >= 0;
	if (has_newline)
		return (split_string_from_newline(line_acc,
				gnl, newline_position));
	is_empty_string = ft_strlen(*line_acc) > 0;
	if (is_empty_string)
	{
		line_with_newline = *line_acc;
		*(*gnl)->current_buffer = '\0';
	}
	return (line_with_newline);
}

char	*find_next_line(t_gnl **gnl)
{
	char	*line_with_newline;
	char	*line_acc;
	ssize_t	newline_position;
	ssize_t	bytes_read;

	bytes_read = BUFFER_SIZE;
	line_acc = ft_strdup((*gnl)->current_buffer);
	while (!ft_strchr_custom(line_acc, NEW_LINE, &newline_position)
		&& bytes_read == BUFFER_SIZE)
	{
		bytes_read = read((*gnl)->fd, (*gnl)->current_buffer, BUFFER_SIZE);
		(*gnl)->current_buffer[bytes_read] = '\0';
		line_acc = ft_strjoin_custom(line_acc, (*gnl)->current_buffer);
	}
	line_with_newline = new_line_handler(gnl, &line_acc, newline_position);
	if (line_with_newline)
		return (line_with_newline);
	if (bytes_read == END_OF_FILE || bytes_read == FILE_NOT_FOUND
		|| (*gnl)->fd < 0)
	{
		free(line_acc);
		line_acc = NULL;
		return (NULL);
	}
	return (line_with_newline);
}

void	move_fd_head_list(t_gnl **gnl_list, int fd)
{
	t_gnl	*new_gnl;
	t_gnl	*previous_gnl;

	new_gnl = *gnl_list;
	while (new_gnl && new_gnl->fd != fd)
	{
		previous_gnl = new_gnl;
		new_gnl = new_gnl->next_gnl;
	}
	if (new_gnl && new_gnl != *gnl_list)
	{
		previous_gnl->next_gnl = new_gnl->next_gnl;
		new_gnl->next_gnl = *gnl_list;
		*gnl_list = new_gnl;
	}
	if (!new_gnl)
	{
		new_gnl = (t_gnl *)malloc(sizeof(t_gnl));
		if (!new_gnl)
			return ;
		new_gnl->fd = fd;
		*(new_gnl->current_buffer) = '\0';
		new_gnl->next_gnl = *gnl_list;
		*gnl_list = new_gnl;
	}
}

char	*get_next_line(int fd)
{
	static t_gnl	*gnl;
	char			*line_result;
	t_gnl			*tmp;

	move_fd_head_list(&gnl, fd);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	line_result = find_next_line(&gnl);
	if (!line_result)
	{
		tmp = gnl->next_gnl;
		free(gnl);
		gnl = tmp;
		return (NULL);
	}
	return (line_result);
}
