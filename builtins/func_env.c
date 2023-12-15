/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:13 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/15 18:36:34 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*falta teste*/
void	func_env(t_cmd	cmds)
{
	int	i;

	i = -1;
	if (cmds.arg[1])
	{
		ft_putstr_fd("Error: too many arguments\n", 2);
		data()->exit_status = 1;
		return ;
	}
	else
	{
		i = 0;
		while (data()->copy_env[i])
		{
			ft_putendl_fd(data()->copy_env[i], dup(STDOUT_FILENO));
			i++;
		}
	}
}
