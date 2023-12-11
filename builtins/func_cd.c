/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:33:49 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/11 12:24:04 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*home(char **env);
void	cd_error(char *token);
void	func_cd(t_cmd cmds);

char	*home(char **env)
{
	int		i;
	int		j;
	int		n;
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
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 1);
}

void	func_cd(t_cmd cmds)
{
	char	*home_path;

	home_path = home(data()->copy_env);
	if (cmds.arg[1] == NULL || !ft_strncmp(cmds.arg[1], "~", 1))
		chdir(home_path);
	else if (cmds.arg[2])
	{
		data()->exit_status = EXIT_FAILURE;
		ft_putstr_fd("cd: too many arguments\n", 2);
	}
	else if (chdir(cmds.arg[1]) == -1)
		cd_error(cmds.arg[1]);
}
