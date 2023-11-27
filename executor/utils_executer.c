/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:43:05 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/27 22:31:13 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_str(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str[i] == '=')
			printf("\"");
		else
		{
			printf("declare -x %s\n", str);
		}
	}
}

int	is_path(char *cmd)
{
	int	i;

	i = 0;
	while(cmd[i])
	{
		if (cmd[i] == '/' || cmd[i] == '.')
			return (1);
		i++;
	}
	return (0);
}
void	number_cmds(t_cmd cmds)
{
	if (data()->n_cmd == 1)
	{
		if (!ft_strncmp(cmds.cmd, "exit", 4) && ft_strlen(cmds.cmd) == 4)
		{
			func_exit(cmds);
		}
	}
}
