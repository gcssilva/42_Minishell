/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:45:43 by gmorais-          #+#    #+#             */
/*   Updated: 2023/10/30 12:07:52 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*falta teste*/

#include "../inc/minishell.h"

void	func_export(char **line, char ***env)
{
	int	i;

	i = 0;
	if (!line[1])
		func_env(*env);
	else
	{
		while (line[i])
		{
			if (ft_strchr(line[i], '='))
				add_var(line[i], env);
			else
				ft_putstr_fd("export: not an identifier\n", 2);
			i++;
		}
	}
}
