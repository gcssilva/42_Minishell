/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:45:43 by gmorais-          #+#    #+#             */
/*   Updated: 2023/10/23 14:01:38 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*falta teste*/

#include "../inc/minishell.h"

void	func_export(char **line, char ***env, int fd)
{
	int	i;

	i = 0;
	if (!line[1])
		func_env(*env, fd);
	else
	{
		while (line[i])
		{
			if (ft_strchr(line[i], '='))
				add_var(line[i], env);
			else
				ft_putstr_fd("export: not an identifier\n", fd);
			i++;
		}
	}
}