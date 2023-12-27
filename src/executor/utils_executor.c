/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:43:05 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/22 17:35:03 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	print_aspas(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = -1;
	while (*str && str[++i])
	{
		ft_putchar_fd(str[i], 1);
		if (str[i] == '=')
		{
			if (flag == 0)
			{
				ft_putchar_fd('"', 1);
				flag = 1;
			}
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
	int	flag;

	i = -1;
	while (env && env[++i] != NULL)
	{
		if (env[i][0] == '_' && env[i][1] == '=')
			continue ;
		ft_putstr_fd("declare -x ", 1);
		flag = print_aspas(env[i]);
		if (flag == 1)
			ft_putchar_fd('"', 1);
		ft_putchar_fd('\n', 1);
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

int	is_builtin(t_cmd *cmds)
{
	if (!cmds->cmd)
		return (1);
	if (!ft_strncmp(cmds->cmd, "env", 3) && ft_strlen(cmds->cmd) == 3)
		return (1);
	else if (!ft_strncmp(cmds->cmd, "exit", 4) && ft_strlen(cmds->cmd) == 4)
		return (1);
	else if (!ft_strncmp(cmds->cmd, "cd", 2) && ft_strlen(cmds->cmd) == 2)
		return (1);
	else if (!ft_strncmp(cmds->cmd, "export", 6) && ft_strlen(cmds->cmd) == 6)
		return (1);
	else if (!ft_strncmp(cmds->cmd, "unset", 5) && ft_strlen(cmds->cmd) == 5)
		return (1);
	return (0);
}
