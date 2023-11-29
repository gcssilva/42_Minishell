/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:35:27 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/29 18:05:43 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	last_space(char **arg, int i)
{;
	if(arg[i + 1] == NULL)
		return (1);
	else
		return (0);
}

static void	echo_print(t_cmd cmd, int flag)
{
	int	i;

	i = flag;
	while (cmd.arg[++i])
	{
		ft_putstr_fd(cmd.arg[i], dup(STDOUT_FILENO));
		if(last_space(cmd.arg, i) == 0)
			ft_putchar_fd(' ', dup(STDOUT_FILENO));
	}
	if (!flag)
		ft_putstr_fd("\n", dup(STDOUT_FILENO));
	else
		write(dup(STDOUT_FILENO), "\e[38;5;0;48;5;255m%\e[0m\n", 24);
}

void	func_echo(t_cmd cmds)
{
	if (!cmds.arg[1])
		ft_putchar_fd('\n', dup(STDOUT_FILENO));
	else if(!ft_strncmp(cmds.arg[1], "-n", 2) && ft_strlen(cmds.arg[1]) == 2)
		echo_print(cmds, 1);
	else
		echo_print(cmds, 0);
}
