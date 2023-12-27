/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:13 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/20 18:36:33 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	eq_sign(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			return (1);
	}
	return (0);
}

void	func_env(t_cmd	*cmds)
{
	int	i;

	i = -1;
	if (cmds->arg[1])
	{
		ft_putstr_fd("Error: too many arguments\n", 2);
		data()->exit_status = 1;
		return ;
	}
	else
	{
		i = -1;
		while (data()->copy_env[++i])
		{
			if (eq_sign(data()->copy_env[i]))
				ft_putendl_fd(data()->copy_env[i], STDOUT_FILENO);
		}
	}
}
