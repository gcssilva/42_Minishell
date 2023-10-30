/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:40:01 by gmorais-          #+#    #+#             */
/*   Updated: 2023/10/23 12:32:28 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	delete_var(char *line, char ***env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], line, ft_strlen(line)) == 0)
		{
			free((*env)[i]);
			while ((*env)[i + j])
			{
				(*env)[i + j] = (*env)[i + j + 1];
				j++;
			}
		}
		i++;
	} 
}

int	exist_var(char *line, char ***env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], line, ft_strlen(line)) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	func_unset(char **line, char ***env)
{
	if(line[1] && !line[2])
	{
		if(exist_var(line[1], *env))
			delete_var(line[1], env);
		else
		{
			ft_putstr_fd("unset: \ ", 2);
			ft_putstr_fd(line[1], 2);
			ft_putstr_fd(" : not a valid identifier\n", 2);
		}
	}
}
