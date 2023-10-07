/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:33:49 by gmorais-          #+#    #+#             */
/*   Updated: 2023/10/07 15:02:58 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//work on progress

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

void	func_cd(char **line, char **env)
{
	char	*old_path;
	char	*current_path;
	char	*home_path;
	
	old_path = getcwd(NULL, 1025);
	home_path = home(*env);
}