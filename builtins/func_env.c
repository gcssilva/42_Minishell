/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:13 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/29 17:12:23 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*falta teste*/
void	func_env(int flag)
{
	int	i;

	i = -1;
	if (!data()->copy_env)
	{
		ft_putstr_fd("Error: env not found\n", 2);
		return ;
	}
	if(flag == 1)
	{
		while (data()->copy_env[++i])
		{
			if (data()->copy_env[i][0] == '_' && data()->copy_env[i][1] == '=')
				continue ;
			print_str(data()->copy_env[i]);
		}
	}
	else
	{
		while (data()->copy_env[++i])
			ft_putendl_fd(data()->copy_env[i], dup(STDOUT_FILENO));
	}
}
