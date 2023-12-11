/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:43:05 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/11 12:30:36 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	print_aspas(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = -1;
	while (*str && str[++i])
	{
		printf("%c", str[i]);
		if (str[i] == '=')
		{
			printf("\"");
			flag = 1;
		}
	}
	return (flag);
}

int	strrlen(char *str, char c)
{
	int	len;

	len = -1;
	if (!str)
		return (0);
	while (str[++len] && str[len] != c)
		;
	return (len + (str[len] == c));
}

void	print_export(char **env)
{
	int	i;
	int	len;
	int	flag;

	i = 0;
	while (env && env[i] != NULL)
	{
		printf("declare -x ");
		len = strrlen(env[i], '=');
		flag = print_aspas(env[i]);
		if (flag == 1)
			printf("\"");
		printf("\n");
		i++;
	}
}

int	is_path(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/' || cmd[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int	is_builtin(t_cmd cmds)
{
	if (!ft_strncmp(cmds.cmd, "pwd", 3) && ft_strlen(cmds.cmd) == 3)
		return (1);
	else if (!ft_strncmp(cmds.cmd, "echo", 4) && ft_strlen(cmds.cmd) == 4)
		return (1);
	else if (!ft_strncmp(cmds.cmd, "env", 3) && ft_strlen(cmds.cmd) == 3)
		return (1);
	else if (!ft_strncmp(cmds.cmd, "exit", 4) && ft_strlen(cmds.cmd) == 4)
		return (1);
	else if (!ft_strncmp(cmds.cmd, "cd", 2))
		return (1);
	else if (!ft_strncmp(cmds.cmd, "export", 6))
		return (1);
	else if (!ft_strncmp(cmds.cmd, "unset", 5))
		return (1);
	return (0);
}
