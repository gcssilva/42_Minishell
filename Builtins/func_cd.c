/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:33:49 by gmorais-          #+#    #+#             */
/*   Updated: 2023/10/24 15:41:15 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//work on progress

void	update_env(char *old_path, char *new_path, char ***env)
{
	int	i;

	i = 0;
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], "OLDPWD=", 7) == 0)
		{
			if ((*env)[i])
				free((*env)[i]);
			(*env)[i] = ft_strjoin("OLDPWD=", old_path);
		}
		if (ft_strncmp((*env)[i], "PWD=", 4) == 0)
		{
			if ((*env)[i])
				free((*env)[i]);
			(*env)[i] = ft_strjoin("PWD=", new_path);
			if (new_path)
				free(new_path);
		}
		i++;
	}
}

char	*home(char **env)
{
	int		i;
	int		j;
	int 	n;
	char	*home;
	
	i = 0;
	n = 0;
	home = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
		{
			j = 5;
			home = malloc(sizeof(char) * ft_strlen(env[i]));
			while (env[i][j + n])
			{
				home[n] = env[i][j + n];
				n++;
			}
			home[n] = '\0';
			return (home);
		}
		i++;
	}
	return (home);
}

void	cd_error(char *token)
{
	ft_putstr_fd("cd: ", 1);
	ft_putstr_fd(token, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(strerror(errno), 1);
	ft_putstr_fd("\n", 1);
}

void	func_cd(char **line, char **env)
{
	char	*old_path;
	char	*new_path;
	char	*home_path;
	
	old_path = getcwd(NULL, 1025);
	home_path = home(*env);
	if(!line)
		chdir(home_path);
	else if (chdir(home_path) == -1)
	{
		cd_error(home_path);
		free(home_path);
		free(old_path);
		return ;
	}
	new_path = getcwd(NULL, 1025);
	update_env(old_path, new_path, &env);
	free(home_path);
	free(old_path);
}