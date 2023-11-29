/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:03:57 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/29 12:58:19 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*falta teste*/

#include "../inc/minishell.h"

// int	num_exit(int num)
// {
// 	if (num >= 0 && num <= 255)
// 		return (num);
// 	else
// 		return (num % 256);
// }

// int	type_exit(t_cmd cmds)
// {
// 	int i;

// 	i = 0;
// 	if (cmds.arg[1][i])
// 	{
// 		if (cmds.arg[1][i] < '0' && cmds.arg[1][i] > '9')
// 		{
// 			ft_putstr_fd("exit: ", 2);
// 			ft_putstr_fd("exit: ", 2);
// 			ft_putstr_fd(cmds.arg[1], 2);
// 			ft_putendl_fd(": numeric argument required", 2);
// 			return (255);
// 		}
// 	}
// 	i = -1;
// 	if (ft_isdigit(ft_atoi(cmds.arg[++i])))
// 	{
// 		ft_putstr_fd("exit\n", 1);
// 		return (num_exit(ft_atoi(cmds.cmd)));
// 	}
// 	return (0);
// }

int	treat_exit_arg(char *str)
{
	int	i;
	int	nb;
	int	flag;

	i = 0;
	nb = 0;
	flag = 0;
	while (str[i] == '"' || str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag = 1;
		i++;
	}
	nb = ft_atoi(&str[i]);
	if (flag)
		nb *= -1;
	return (nb);
}

void	func_exit(t_cmd cmds)
{
	ft_putstr_fd("exit\n", 1);
	if (cmds.arg[1] && cmds.arg[2])
	{
		ft_putendl_fd("exit: too many arguments", 2);
		data()->exit_status = EXIT_FAILURE;
	}
	else if (cmds.arg[1] && !is_numeric(cmds.arg[1]))
	{
		ft_putendl_fd("exit: numeric argument required", 2);
		data()->exit_status = 255;
		exit (data()->exit_status);
	}
	else if (cmds.arg[1] && is_numeric(cmds.arg[1]))
	{
		data()->exit_status = treat_exit_arg(cmds.arg[0]);
		if (data()->exit_status < 0)
			data()->exit_status = (data()->exit_status + 256);
		data()->exit_status = data()->exit_status % 256;
		exit(data()->exit_status);
	}
	exit(data()->exit_status);
}

int	is_numeric(char *arg)
{
	int	i;
	int	f_plus;
	int	f_minus;

	f_plus = 0;
	f_minus = 0;
	i = -1;
	while (arg[++i])
	{
		if (arg[i] == '-')
		{
			if (f_minus)
				return (0);
			f_minus = 1;
		}
		if (arg[i] == '+')
		{
			if (f_plus)
				return (0);
			f_plus = 1;
		}
		if (ft_isalpha(arg[i]))
			return (0);
	}
	return (1);
}
// void	func_exit(t_cmd cmds)
// {
// 	int	status;
// 	int	i;

// 	status = 0;
// 	i = -1;
// 	if (!cmds.arg[1])
// 	{
// 		ft_putstr_fd("exit\n", 1);
// 		exit_status = 0;
// 		return ;
// 	}
// 	else
// 	{
// 		status = type_exit(cmds);
// 		//printf("cheguei aqui %i\n", cmds.saida);
// 		exit_status = status;
// 		return ;
// 	}
// 	printf("cheguei aqui %s\n", cmds.arg[1]);
// 	while (data()->copy_env[++i])
// 		free (data()->copy_env[i]);
// 	free (data()->copy_env);
// 	return ;	
// }
