/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:14:16 by coder             #+#    #+#             */
/*   Updated: 2022/08/20 17:25:41 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define FILE_NOT_FOUND -1
# define END_OF_FILE 0
# define NEW_LINE '\n'

char	*get_next_line(int fd);
int		ft_strchr_custom(const char *s, int c, ssize_t *newline_position);
char	*ft_strjoin_custom(char *s1, char *s2);

#endif