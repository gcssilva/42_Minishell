/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executer_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:32:58 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/14 19:28:54 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_unset(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=' && str[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

int	check_export(t_cmd cmds)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data()->ord_env[i][j])
	{
		if (ft_strncmp(data()->ord_env[i], cmds.arg[1],
				var_len(cmds.arg[1])) != 0)
			i++;
		else
			return (-1);
	}
	return (0);
}
