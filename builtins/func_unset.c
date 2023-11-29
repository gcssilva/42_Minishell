/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:40:01 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/29 18:05:43 by gsilva           ###   ########.fr       */
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

int    exist_var(t_cmd cmds, int flag)
{
    int    i;

    i = -1;
    while (data()->copy_env[++i])
    {
        if (flag)
            {
                if (ft_strncmp(data()->copy_env[i], cmds.arg[1], var_len(cmds.arg[1])) == 0)
                    return (1);
            }
        if (ft_strncmp(data()->copy_env[i], cmds.arg[1], ft_strlen(cmds.arg[1])) == 0)
            return (1);
    }
    return (0);
}

void	func_unset(t_cmd cmds)
{
	if(cmds.arg[1] && !cmds.arg[2])
	{
		if(exist_var(cmds, 0))
			delete_arg(cmds);
		else
		{
			ft_putstr_fd("unset: ", 2);
			ft_putstr_fd(cmds.arg[1], 2);
			ft_putendl_fd(": not a valid identifier", 2);
		}
	}
}
