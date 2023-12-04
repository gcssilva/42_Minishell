/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:20:31 by gsilva            #+#    #+#             */
/*   Updated: 2023/12/04 17:53:05 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	n_cmds(char	*input);
int		ft_isblank(int c);
int		ft_isredir(int c);

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
