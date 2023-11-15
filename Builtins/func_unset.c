/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:40:01 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/15 12:44:39 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	delete_var(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data()->copy_env[i])
	{
		if (ft_strncmp(data()->copy_env[i], line, ft_strlen(line)) == 0)
		{
			free(data()->copy_env[i]);
			while (data()->copy_env[i + j])
			{
				data()->copy_env[i + j] = data()->copy_env[i + j + 1];
				j++;
			}
		}
		i++;
	} 
}

int	exist_var(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data()->copy_env[i])
	{
		if (ft_strncmp(data()->copy_env[i], line, ft_strlen(line)) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	func_unset(char **line)
{
	if(line[1] && !line[2])
	{
		if(exist_var(line[1]))
			delete_var(line[1]);
		else
		{
			ft_putstr_fd("unset: \ ", 2);
			ft_putstr_fd(line[1], 2);
			ft_putstr_fd(" : not a valid identifier\n", 2);
		}
	}
}
