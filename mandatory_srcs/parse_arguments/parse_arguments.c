/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:53:42 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/13 18:47:32 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_access_bin(t_cmd *cmd)
{
	int	is_valid;

	is_valid = FALSE;
	if (access(cmd->cmd, R_OK) == SUCESS_CODE)
		return (TRUE);
	free(cmd->cmd);
	cmd->cmd = NULL;
	return (is_valid);
}

int	parse_command_bin(t_arguments *arguments, int index)
{
	char	**path_split;
	char	*path_with_slash;
	int		i;
	int		is_valid_bin;

	path_split = ft_split(arguments->path, COMMA_CHAR);
	i = 0;
	is_valid_bin = FALSE;
	while (path_split[i])
	{
		path_with_slash = ft_strjoin(path_split[i], SLASH_STRING);
		if (is_valid_bin == FALSE)
		{
			arguments->commands[index].cmd = ft_strjoin(path_with_slash,
					arguments->commands[index].cmd_to_parse[0]);
			is_valid_bin = check_access_bin(&arguments->commands[index]);
		}
		free(path_with_slash);
		free(path_split[i]);
		i++;
	}
	free(path_split);
	return (is_valid_bin);
}

void	parse_commands(t_arguments *arguments)
{
	int	i;
	int	j;

	arguments->number_commands = arguments->argc
		- COMMANDS_OFFSET;
	arguments->commands = (t_cmd *)malloc(sizeof(t_cmd)
			* arguments->number_commands);
	i = INDEX_COMMANDS_START;
	j = 0;
	while (i < arguments->argc - 1)
	{
		init_cmd(&arguments->commands[j]);
		arguments->commands[j].cmd_to_parse = tokenizer(arguments, i);
		parse_command_bin(arguments, j);
		parse_cmd(&arguments->commands[j]);
		i++;
		j++;
	}
}

void	parse_path(t_arguments *arguments)
{
	int		i;
	size_t	path_len;

	i = 0;
	path_len = ft_strlen(PATH);
	while (arguments->envp[i])
	{
		if (ft_strnstr(arguments->envp[i], PATH, path_len))
		{
			arguments->envp[i] = arguments->envp[i] + path_len;
			arguments->path = ft_strdup(arguments->envp[i]);
		}
		i++;
	}
}

int	parse_args(t_arguments *arguments)
{
	if (arguments->argc <= MINIMUM_NUMBER_ARGS)
		exit_with_message(ERROR_CODE, TOO_FEW_ARGUMENTS_ERROR_MSG);
	arguments->input_file.file_name = arguments->argv[1];
	arguments->output_file.file_name = arguments->argv[arguments->argc - 1];
	parse_path(arguments);
	parse_commands(arguments);
	return (0);
}
