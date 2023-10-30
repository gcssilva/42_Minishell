/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:55:27 by gmorais-          #+#    #+#             */
/*   Updated: 2023/10/24 15:49:00 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*find_path(char *cmd, char **env, int i)
{
	char	**paths;
	char	*path;
	char	*part_path;

	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
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
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	func_exec(char **line, char **env)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	path = find_path(line[0], env, 0);
	if (!path)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 1);
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
	}
	if (execve(path, line, env) == -1)
		ft_putstr_fd("error execve\n", 2);
}
