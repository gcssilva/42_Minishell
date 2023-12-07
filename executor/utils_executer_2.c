/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executer_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:32:58 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/07 16:02:23 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_unset(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i++])
	{
		if (str[i] == '=' && str[i + 1])
		{
			printf("merda\n");
			return (-1);
		}
	}
	return (0);
}

int    exist_export(t_cmd cmds)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (data()->copy_env[i++])
	{
		if (ft_strncmp(data()->copy_env[i], cmds.arg[1], var_len(cmds.arg[1])) == 0)
		{
			if (check_unset(data()->copy_env[i]) == -1)
				flag = 1;
			else
				flag = -1;
		}
	}
	if (flag == 1)
		return (1);
	else if (flag == -1)
		return (-1);
	return (0);
}
