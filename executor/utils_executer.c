/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:43:05 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/28 12:08:48 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


void	print_str(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = -1;
	printf("declare -x ");
	while (str[++i])
	{
		printf("%c", str[i]);
		if (str[i] == '=')
		{
			printf("\"");
			printf("%c", str[i + 1]);
			flag = 1;
			i++;
		}
	}
	if (flag == 1)
		printf("\"");
	printf("\n");
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
