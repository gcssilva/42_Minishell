/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:40:01 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/11 12:28:58 by gmorais-         ###   ########.fr       */
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

void	delete_arg(t_cmd cmds)
{
	int		i;
	int		j;
	char	**copy_env;

	i = 0;
	while (data()->copy_env[i++])
		;
	copy_env = malloc(sizeof(char *) * (i));
	j = 0;
	i = -1;
	while (data()->copy_env[++i])
	{
		if (ft_strncmp(data()->copy_env[i], cmds.arg[1],
				var_len(data()->copy_env[i])) != 0)
		{
			copy_env[j] = data()->copy_env[i];
			j++;
		}
		else
			free(data()->copy_env[i]);
	}
	copy_env[j] = NULL;
	free(data()->copy_env);
	data()->copy_env = copy_env;
}

int	exist_var(t_cmd cmds)
{
	int	i;

	i = 0;
	while (data()->copy_env[i])
	{
		if (ft_strncmp(data()->copy_env[i], cmds.arg[1],
				var_len(cmds.arg[1])) != 0)
			i++;
		else
			return (-1);
	}
	return (0);
}

void	func_unset(t_cmd cmds)
{
	if (cmds.arg[1] && !cmds.arg[2])
	{
		if (exist_var(cmds))
			delete_arg(cmds);
		else
		{
			ft_putstr_fd("unset: ", 2);
			ft_putstr_fd(cmds.arg[1], 2);
			ft_putendl_fd(": not a valid identifier", 2);
		}
	}
}
