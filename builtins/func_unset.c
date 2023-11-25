/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:40:01 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/25 15:28:44 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	var_len(char *var)
{
	int	len;

	len = 0;
	while (var[len] != '=' && var[len] != '\0')
		len++;
	return (len);
}

void	delete_var(t_cmd cmds)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data()->copy_env[i])
	{
		if (ft_strncmp(data()->copy_env[i], cmds.cmd, ft_strlen(cmds.cmd)) == 0)
		{
			free(data()->copy_env[i]);
			while (data()->copy_env[i + j])
			{
				data()->copy_env[i + j] = data()->copy_env[i + j + 1];
				j++;
			}
		}
		i++;
	} 
}

int	exist_var(t_cmd cmds)
{
	int	i;

	i = 0;
	while (data()->copy_env[i])
	{
		if (ft_strncmp(data()->copy_env[i], cmds.cmd, ft_strlen(cmds.cmd)) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	func_unset(t_cmd cmds)
{
	if(cmds.cmd[1] && !cmds.arg[2])
	{
		if(exist_var(cmds))
			delete_var(cmds);
		else
		{
			ft_putstr_fd("unset: ", 2);
			ft_putstr_fd(cmds.arg[1], 2);
			ft_putendl_fd(": not a valid identifier", 2);
		}
	}
}
