/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:45:43 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/25 15:30:26 by gmorais-         ###   ########.fr       */
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

void	delete_arg(char *var)
{
	int		i;
	int		j;
	char	**copy_env;

	i = 0;
	while (data()->copy_env[i])
		i++;
	copy_env = malloc(sizeof(char *) * (i));
	j = 0;
	i = -1;
	while (data()->copy_env[++i])
	{
		if (ft_strncmp(data()->copy_env[i], var, var_len(data()->copy_env[i])) != 0)
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

void	add_var(t_cmd cmds)
{
	int		i;
	char	**copy_env;

	i = 0;
	if (exist_var(cmds))
		delete_arg(cmds.arg[1]);
	while (data()->copy_env[i])
		i++;
	copy_env = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (data()->copy_env[i])
	{
		copy_env[i] = data()->copy_env[i];
		i++;
	}
	copy_env[i] = ft_strdup(cmds.arg[1]);
	copy_env[i + 1] = NULL;
	free(data()->copy_env);
	data()->copy_env = copy_env;
}


void    func_export(t_cmd cmds)
{
    if (!cmds.arg[1])
        func_env();
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
