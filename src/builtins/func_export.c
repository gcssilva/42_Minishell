/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:45:43 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/22 17:33:40 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	valid_var(char *var)
{
	int	i;

	i = 0;
	if (ft_isdigit(var[i]) || var[i] == '=')
		return (0);
	while (var[i] && var[i] != '=')
	{
		if (!ft_isalnum(var[i]) && var[i] != '_' && var[i] != '=')
			return (0);
		i++;
	}
	return (1);
}

char	**add_new_var(char **env, char *var)
{
	int		i;
	int		j;
	int		x;
	char	**new_env;

	i = 0;
	j = -1;
	while (env[i])
		i++;
	x = i;
	new_env = malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (++i < x)
		new_env[++j] = ft_strdup(env[i]);
	new_env[i] = ft_strdup(var);
	new_env[i + 1] = NULL;
	i = -1;
	while (env[++i] != NULL)
		free(env[i]);
	free(env);
	return (new_env);
}

void	add_var(t_cmd *cmds, int a)
{
	if (exist_var(cmds, a) != -1)
	{
		check_export(cmds, a);
		return ;
	}
	(data()->copy_env) = add_new_var(data()->copy_env, cmds->arg[a]);
	(data()->ord_env) = add_new_var(data()->ord_env, cmds->arg[a]);
	asci_ord (data()->ord_env);
}

void	func_export(t_cmd *cmds)
{
	int	i;

	i = 0;
	if (!cmds->arg[1])
		print_export(data()->ord_env);
	else
	{
		while (cmds->arg[++i])
		{
			if (valid_var(cmds->arg[i]))
				add_var(cmds, i);
			else
			{
				ft_putstr_fd("export: \'", 2);
				ft_putstr_fd(cmds->arg[i], 2);
				ft_putstr_fd("\': not a valid identifier\n", 2);
				data()->exit_status = 1;
			}
		}
	}
}
