/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:45:43 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/11 12:33:55 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*falta teste*/
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

void	add_var(t_cmd cmds)
{
	int		x;
	int		i;
	int		j;
	char	**copy;

	i = 0;
	j = -1;
	if (exist_var(cmds) == -1)
		check_export(cmds);
	while (data()->copy_env[i])
		i++;
	x = i;
	copy = malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (++i < x)
	{
		copy[++j] = ft_strdup(data()->copy_env[i]);
	}
	copy[i] = ft_strdup(cmds.arg[1]);
	copy[i + 1] = NULL;
	i = -1;
	while (data()->copy_env[++i] != NULL)
		free(data()->copy_env[i]);
	free(data()->copy_env);
	data()->copy_env = copy;
}

void	func_export(t_cmd cmds)
{
	if (!cmds.arg[1])
		print_export(data()->copy_env);
	else
	{
		if (valid_var(cmds.arg[1]))
			add_var(cmds);
		else
		{
			ft_putstr_fd("export: \'", 2);
			ft_putstr_fd(cmds.arg[1], 2);
			ft_putstr_fd("\': not a valid identifier\n", 2);
		}
	}
}
