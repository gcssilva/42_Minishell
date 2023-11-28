/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:13 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/28 11:19:58 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*falta teste*/
void	func_env(int flag)
{
	int		i;

	i = -1;
	if(flag == 1)
	{
		while (data()->copy_env[++i])
			print_str(data()->copy_env[i]);
	}
	if (!data()->copy_env)
	{
		ft_putstr_fd("Error: env not found\n", 2);
		return ;
	}
	while (data()->copy_env[++i])
	{
		ft_putendl_fd(data()->copy_env[i], 1);
	}
}
