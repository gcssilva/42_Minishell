/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:20:31 by gsilva            #+#    #+#             */
/*   Updated: 2023/12/17 15:10:30 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	n_cmds(char	*input);
int		ft_isblank(int c);
int		ft_isredir(int c);
void	inicialize_stuct(void);

void	inicialize_stuct(void)
{
	int	i;

	i = -1;
	while (++i < data()->n_cmd)
	{
		data()->cmds[i].arg[0] = 0;
		data()->cmds[i].red[0] = 0;
		data()->cmds[i].order[0] = 0;
	}
}

void	n_cmds(char	*input)
{
	int	i;
	int	cmds;

	i = -1;
	cmds = 1;
	while (input[++i])
	{
		if (input[i] == '|')
			cmds += 1;
		else if (input[i] == '"')
		{
			while (input[++i] != '"')
				continue ;
		}
		else if (input[i] == '\'')
		{
			while (input[++i] != '\'')
				continue ;
		}
	}
	data()->n_cmd = cmds;
	data()->cmds = (t_cmd *)malloc(sizeof(t_cmd) * (cmds + 1));
	inicialize_stuct();
}

int	ft_isblank(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_isredir(int c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}
