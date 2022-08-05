/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:59:50 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/29 02:49:46 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_with_message(int status_code, char *message)
{
	if (status_code == ERROR_CODE)
		ft_printf(RED"%s\n",message);
	else
		ft_printf(GREEN"%s\n",message);
	exit(status_code);
}

void	print_arg_error(char *arg, int status_code, char *message)
{
		ft_printf("arg: %s - ", arg);
		exit_with_message(status_code, message);
}

void	load_file(t_arguments *arguments)
{
	arguments->input_file.file_name = arguments->argv[1];
	arguments->input_file.fd = open(arguments->input_file.file_name, O_RDONLY);
	arguments->output_file.file_name = arguments->argv[arguments->argc - 1];
	arguments->output_file.fd = open(arguments->output_file.file_name, O_RDONLY);
	if (arguments->input_file.fd < 0)
		print_arg_error(arguments->input_file.file_name,
			ERROR_CODE, FILE_NOT_FOUND_ERROR_MSG);
	if (arguments->output_file.fd < 0)
		print_arg_error(arguments->output_file.file_name,
			ERROR_CODE, FILE_NOT_FOUND_ERROR_MSG);
}

void	load_args(int argc, char *argv[], char *envp[], t_arguments *arguments)
{
	arguments->argc = argc;
	arguments->argv = argv;
	arguments->envp = envp;
}

void	parse_cmd(t_cmd *cmd)
{
	int	i;
	
	
	i = 0;
	while (cmd->cmd_to_parse[i])
		++i;
	cmd->argv = (char **)malloc(sizeof(char *) * i);
	cmd->cmd = cmd->cmd_to_parse[0];
	i = 1;
	while (cmd->cmd_to_parse[i])
	{
		cmd->argv[i - 1] = cmd->cmd_to_parse[i];
		i++;
	}
	cmd->argv[i - 1] = NULL;
}

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
		arguments->commands[j].cmd_to_parse =
			ft_split(arguments->argv[i++], ' ');
		parse_cmd(&arguments->commands[j++]);
	}
}

void	free_args(t_arguments *arguments)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (i < arguments->number_commands)
	{
		j = 0;
		while (arguments->commands[i].cmd_to_parse[j])
		{
			free(arguments->commands[i].cmd_to_parse[j]);
			j++;
		}
		free(arguments->commands[i].argv);
		free(arguments->commands[i].cmd_to_parse);
		i++;
	}	free(arguments->commands);
}

int	parse_args(t_arguments *arguments)
{
	if (arguments->argc <= MINIMUM_NUMBER_ARGS)
		exit_with_message(ERROR_CODE, TOO_FEW_ARGUMENTS_ERROR_MSG);
	arguments->input_file.file_name = arguments->argv[1];
	arguments->output_file.file_name = arguments->argv[arguments->argc - 1];
	parse_commands(arguments);
	ft_printf("input_file: %s\n", arguments->input_file.file_name);
	ft_printf("command 1:%s argv: %s\n", arguments->commands[0].cmd,  arguments->commands[0].argv[0]);
	ft_printf("command 2:%s argv: %s\n", arguments->commands[1].cmd, arguments->commands[1].argv[0]);
	ft_printf("output_file: %s\n", arguments->output_file.file_name);
	free_args(arguments);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arguments	arguments;

	load_args(argc, argv, envp, &arguments);
	parse_args(&arguments);
	return (0);
}
