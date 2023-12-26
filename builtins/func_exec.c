/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:55:27 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/22 18:15:38 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		check(char *cmd);
char	*find_path(char *cmd, char **env, int i);
void	func_exec(t_cmd *cmds);

int	check(char *cmd)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	if (!cmd)
		return (0);
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '/')
			flag = 1;
		if (flag == 1)
		{
			if (access(cmd, F_OK) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

void	free_path(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}

char	*find_path(char *cmd, char **env, int i)
{
	char	**paths;
	char	*path;
	char	*part_path;

	if (check(cmd))
		return (cmd);
	while (env[i] && ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	if (!env[i])
		return (0);
	paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	free_path(paths);
	return (0);
}

void	func_exec(t_cmd *cmds)
{
	char	*path;
	DIR		*dir;

	path = find_path(cmds->cmd, data()->copy_env, 0);
	if (!path)
	{
		if (cmds->cmd[0] == '.' || cmds->cmd[0] == '/')
			ft_putendl_fd("minishell: No such file or directory", 2);
		else
			ft_putendl_fd("minishell: command not found", 2);
		data()->exit_status = 127;
		return ;
	}
	if (execve(path, cmds->arg, data()->copy_env) == -1)
	{
		dir = opendir(path);
		if (!dir)
			ft_putendl_fd(" Permission denied", 2);
		else
		{
			ft_putendl_fd(" Is a directory", 2);
			closedir(dir);
		}
		data()->exit_status = 126;
	}
}
