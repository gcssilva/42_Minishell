/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:35:27 by gmorais-          #+#    #+#             */
/*   Updated: 2023/10/13 16:11:14 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// nao funcional, preciso testar para ver se funciona desta forma

static void	echo_print(char **cmd, int i,  char flag, int fd)
{
	if (flag == "y")
		ft_putstr_fd(cmd, fd);
	else if (flag == "n")
		ft_putendl_fd(cmd, fd);
}

void	func_echo(char **cmd, int fd)
{
	if(!ft_strncmp(cmd[1], "-n", 2))
		echo_print(cmd, 2, "n", fd);
	else if (ft_strncmp(cmd[1], "-n", fd))
		echo_print(cmd, 1, "y", fd);
}
