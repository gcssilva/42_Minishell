/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:45:43 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/17 16:15:10 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	valid_var(char *var)
{
	int	i;

	i = 0;
	if (ft_isdigit(var[i]))
		return (0);
	while (var[i] && var[i] != '=')
	{
		if (!ft_isalnum(var[i]) && var[i] != '_' && var[i] != '=')
			return (0);
		i++;
	}
	return (1);
}

void	add_var(t_cmd cmds, int a, int i, int j)
{
	int		x;
	char	**copy;

	if (exist_var(cmds, a) != 0)
	{
		check_export(cmds, a);
		return ;
	}
	while (data()->ord_env[i])
		i++;
	x = i;
	copy = malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (++i < x)
		copy[++j] = ft_strdup(data()->ord_env[i]);
	copy[i] = ft_strdup(cmds.arg[a]);
	copy[i + 1] = NULL;
	i = -1;
	while (data()->ord_env[++i] != NULL)
		free(data()->ord_env[i]);
	free(data()->ord_env);
	i = -1;
	data()->ord_env = copy;
}

void	func_export(t_cmd cmds)
{
	int	i;

	i = 0;
	if (!cmds.arg[1])
		print_export(data()->ord_env);
	else
	{
		while (cmds.arg[++i])
		{
			if (valid_var(cmds.arg[i]))
				add_var(cmds, i, 0, -1);
			else
			{
				ft_putstr_fd("export: \'", 2);
				ft_putstr_fd(cmds.arg[i], 2);
				ft_putstr_fd("\': not a valid identifier\n", 2);
				data()->exit_status = 1;
			}
		}
	}
}
