/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:03:57 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/21 09:46:54 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*falta teste*/

#include "../inc/minishell.h"

int	num_exit(int num)
{
	if (num >= 0 && num <= 255)
		return (num);
	else
		return (num % 256);
}

int	type_exit(char line)
{
	int	i;

	i = -1;
	while (line)
	{
		if (ft_isascii(line) && !ft_isdigit(line))
		{
			ft_putstr_fd("exit\n", 1);
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd(line, 2);
			ft_putendl_fd(" : numeric argument required", 2);
			return (2);
		}
	}
	i = 0;
	if (ft_isdigit(line))
	{
		ft_putstr_fd("exit\n", 1);
		return (num_exit(ft_atoi(line)));
	}
	return (0);
}

void	func_exit(char cmd)
{
	int	status;
	int	i;

	status = 0;
	i = -1;
	if (!cmd)
	{
		ft_putstr_fd("exit\n", 1);
		status = 0;
	}
	else
		status = type_exit(cmd);
	while (data()->copy_env[++i])
		free (data()->copy_env[i]);
	free (data()->copy_env);
	exit (status);
}