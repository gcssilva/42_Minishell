/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executer_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:32:58 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/22 17:35:27 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_unset(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=' && str[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

int	eq_env(t_cmd *cmds, int a)
{
	int	i;

	i = 0;
	while (data()->copy_env[i])
	{
		if (ft_strncmp(data()->copy_env[i], cmds->arg[a],
				var_len(cmds->arg[a])) != 0)
			i++;
		else
			return (i);
	}
	return (0);
}

void	check_export(t_cmd *cmds, int a)
{
	int	i;
	int	ord;
	int	copy;

	i = -1;
	copy = eq_env(cmds, a);
	ord = exist_var(cmds, a);
	while (cmds->arg[a][++i])
	{
		if (cmds->arg[a][++i] == '=')
		{
			free(data()->ord_env[ord]);
			data()->ord_env[ord] = ft_strdup(cmds->arg[a]);
			free(data()->copy_env[copy]);
			data()->copy_env[copy] = ft_strdup(cmds->arg[a]);
			return ;
		}
	}
}

void	ft_wait(pid_t *pids)
{
	int	e_status;
	int	i;

	i = -1;
	while (++i < data()->n_cmd)
	{
		waitpid(pids[i], &e_status, 0);
		if (WIFEXITED(e_status))
			data()->exit_status = WEXITSTATUS(e_status);
	}
}
