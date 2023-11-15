/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:13 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/15 12:39:50 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*falta teste*/

void	func_env(void)
{
	int	i;

	if (!data()->copy_env)
	{
		ft_putstr_fd("Error: env not found\n", 2);
		return ;
	}
	i = 0;
	while (data()->copy_env[i])
	{
		ft_putstr_fd(data()->copy_env[i], 1);
		ft_putchar('\n');
		i++;
	}
}
