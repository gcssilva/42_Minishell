/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:35:27 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/28 12:09:36 by gmorais-         ###   ########.fr       */
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
		ft_putstr_fd(cmd.arg[i], 2);
		if(last_space(cmd.arg, i) == 0)
			ft_putchar_fd(' ', 2);
	}
	if (flag == 0)
		ft_putstr_fd("\n", 2);
	else
		write(1, "\e[38;5;0;48;5;255m%\e[0m\n", 24);
}

void	func_echo(t_cmd cmds)
{
	if(ft_strncmp(cmds.arg[1], "-n", 2) == 0)
		echo_print(cmds, 1);
	else
		echo_print(cmds, 0);
}
