/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:53:42 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/08/05 23:51:11 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_commands(t_arguments *arguments)
{
	int	i;
	int	j;

	arguments->number_commands = arguments->argc 
		- COMMANDS_OFFSET;
	arguments->commands = (t_cmd *)malloc(sizeof(t_cmd) *
		arguments->number_commands);
	i = INDEX_COMMANDS_START;
	j = 0;
	while (i < arguments->argc - 1)
	{
		init_cmd(&arguments->commands[j]);
		arguments->commands[j].cmd_to_parse =
			ft_split(arguments->argv[i++], ' ');
		parse_cmd(&arguments->commands[j++]);
	}
}

int	parse_args(t_arguments *arguments)
{
	if (arguments->argc <= MINIMUM_NUMBER_ARGS)
		exit_with_message(ERROR_CODE, TOO_FEW_ARGUMENTS_ERROR_MSG);
	arguments->input_file.file_name = arguments->argv[1];
	arguments->output_file.file_name = arguments->argv[arguments->argc - 1];
	parse_commands(arguments);
	
	// ft_printf("input_file: %s\n", arguments->input_file.file_name);
	// int i=0;
	// while (arguments->commands[0].argv[i])
	// {
	// 	ft_printf("%s\n",arguments->commands[0].argv[i]);
	// 	i++;
	// }
	// ft_printf("%s\n",arguments->commands[0].argv[i]);
	// ft_printf("command 1:%s argv: %s\n", arguments->commands[0].cmd,  arguments->commands[0].argv[0]);
	// i=0;
	// while (arguments->commands[0].argv[i])
	// {
	// 	ft_printf("%s\n",arguments->commands[1].argv[i]);
	// 	i++;
	// }
	// ft_printf("%s\n",arguments->commands[1].argv[i]);
	// ft_printf("command 2:%s argv: %s\n", arguments->commands[1].cmd, arguments->commands[1].argv[0]);
	// ft_printf("output_file: %s\n", arguments->output_file.file_name);
	
	
	return (0);
}