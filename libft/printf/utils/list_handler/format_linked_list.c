/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 04:22:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/20 22:01:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format_opt	*find_last_node(t_format_opt *format_opt)
{
	t_format_opt	*last;

	last = format_opt;
	if (!format_opt)
		return (NULL);
	while (last->next_format)
		last = last->next_format;
	return (last);
}

void	clear_list(t_format_opt **format_opt)
{
	t_format_opt	*tmp;

	if (!format_opt)
		return ;
	while (*format_opt)
	{
		tmp = (*format_opt)->next_format;
		free((*format_opt)->format_template);
		free((*format_opt));
		*format_opt = tmp;
	}
}

t_format_opt	*create_node(void)
{
	t_format_opt	*new_node;

	new_node = (t_format_opt *)malloc(sizeof(t_format_opt));
	new_node->next_format = NULL;
	new_node->is_valid = 1;
	ft_bzero(new_node->flags, sizeof(new_node->flags));
	return (new_node);
}

void	add_node_back(t_format_opt **head, t_format_opt *new_node)
{
	t_format_opt	*last;

	if (!head || !new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	last = find_last_node(*head);
	last->next_format = new_node;
}
