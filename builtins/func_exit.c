/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:03:57 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/17 15:14:06 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*falta teste*/

#include "../inc/minishell.h"

int		treat_exit_arg(char *str);
void	func_exit(t_cmd cmds);
int		is_numeric(char *arg);

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
	if (cmds.arg[1])
	{
		ft_putendl_fd("exit: too many arguments", 2);
		data()->exit_status = 1;
	}
	else
	{
		clean_struct();
		exit (0);
	}
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
