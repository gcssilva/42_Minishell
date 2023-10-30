/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:35:27 by gmorais-          #+#    #+#             */
/*   Updated: 2023/10/30 12:03:14 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// nao funcional, preciso testar para ver se funciona desta forma

static void	echo_print(char **cmd, int i,  char flag)
{
	if (flag == "y")
		ft_putstr(cmd);
	else if (flag == "n")
		ft_putendl(cmd);
}

void	func_echo(char **cmd)
{
	if(!ft_strncmp(cmd[1], "-n", 2))
		echo_print(cmd, 2, "n");
	else if (ft_strncmp(cmd[1], "-n", 2))
		echo_print(cmd, 1, "y");
}
