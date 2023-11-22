/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:35:27 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/21 15:24:35 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	last_space(int i, int j)
{;
	if(data()->cmds[i].arg[j + 1] == NULL)
		return (1);
	else
		return (0);
}

static void	echo_print(int flag)
{
	int i;
	int j;

	i = 0;
	if (flag == 0)
	{
		j = 0;
		while (data()->cmds[i].arg[++j])
		{
			ft_putstr_fd(data()->cmds[i].arg[j], 2);
			if(last_space(i, j) == 0)
				ft_putchar_fd(' ', 2);
		}
		ft_putstr_fd("\n", 2);
	}
	else if (flag == 1)
	{
		j = 1;
		while (data()->cmds[i].arg[++j])
		{
			ft_putstr_fd(data()->cmds[i].arg[j], 2);
			if(last_space(i, j) == 0)
				ft_putchar_fd(' ', 2);
		}
	}
}

void	func_echo(void)
{
	int i = 0;
	
	if(!ft_strncmp(data()->cmds[i].arg[1], "-n", 2))
		echo_print(1);
	else if (ft_strncmp(data()->cmds[i].arg[1], "-n", 2))
		echo_print(0);
}
