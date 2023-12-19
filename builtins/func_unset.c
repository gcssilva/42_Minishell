/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:40:01 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/17 15:57:09 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	var_len(char *var)
{
	int	len;

	len = 0;
	while (var && var[len] && var[len] != '=')
		len++;
	return (len);
}

void	delete_arg(t_cmd cmds, int a)
{
	int		i;
	int		j;
	char	**copy_env;

	i = 0;
	while (data()->ord_env[i++])
		;
	copy_env = malloc(sizeof(char *) * (i));
	j = 0;
	i = -1;
	while (data()->ord_env[++i])
	{
		if (ft_strncmp(data()->ord_env[i], cmds.arg[a],
				var_len(data()->ord_env[i])) != 0)
		{
			copy_env[j] = data()->ord_env[i];
			j++;
		}
		else
			free(data()->ord_env[i]);
	}
	copy_env[j] = NULL;
	free(data()->ord_env);
	data()->ord_env = copy_env;
}

int	exist_var(t_cmd cmds, int a)
{
	int	i;

	i = 0;
	while (data()->ord_env[i])
	{
		if (ft_strncmp(data()->ord_env[i], cmds.arg[a],
				var_len(cmds.arg[a])) != 0)
			i++;
		else
			return (i);
	}
	return (-1);
}

void	func_unset(t_cmd cmds)
{
	int	i;

	i = 0;
	while (cmds.arg[++i])
	{
		if (exist_var(cmds, i) != -1)
			delete_arg(cmds, i);
	}
}
