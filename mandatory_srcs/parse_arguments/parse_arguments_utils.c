/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:54:58 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/13 18:47:17 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	load_args(int argc, char *argv[], char *envp[], t_arguments *arguments)
{
	init_args(arguments);
	arguments->argc = argc;
	arguments->argv = argv;
	arguments->envp = envp;
}

void	parse_cmd(t_cmd *cmd)
{
	int	cmd_index;

	cmd_index = 0;
	while (cmd->cmd_to_parse[cmd_index])
		++cmd_index;
	cmd->argv = (char **)malloc(sizeof(char *) * (cmd_index + 1));
	cmd_index = 0;
	while (cmd->cmd_to_parse[cmd_index])
	{
		cmd->argv[cmd_index] = cmd->cmd_to_parse[cmd_index];
		cmd_index++;
	}
	cmd->argv[cmd_index] = NULL;
}
