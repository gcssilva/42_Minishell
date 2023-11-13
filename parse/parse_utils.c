/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:20:31 by gsilva            #+#    #+#             */
/*   Updated: 2023/11/13 00:23:25 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	n_cmds(char	*input)
{
	int	i;
	int	cmds;

	i = -1;
	cmds = 1;
	while(input[++i])
	{
		if (input[i] == '|')
			cmds += 1;
		else if (input[i] == '"')
		{
			while (input[++i] != '"')
				continue;
		}
		else if (input[i] == '\'')
		{
			while (input[++i] != '\'')
				continue;
		}
	}
	data()->n_cmd = cmds;
}

int	check_quotes(char *input)
{
	int	i;
	int	sflag;
	int	dflag;

	i = 0;
	sflag = 0;
	dflag = 0;
	if (input[0] == '\'')
	{
		sflag = 1;
	}
	else if (input[0] == '"')
	{
		dflag = 1;
	}
	while(input[++i])
	{
		if (input[i] == '\'')
		{
			if (dflag == 0 && input[i - 1] != '\\')
			{
				if (sflag == 0)
					sflag = 1;
				else
					sflag = 0;
			}
		}
		else if (input[i] == '"')
		{
			if (sflag == 0 && input[i - 1] != '\\')
			{
				if (dflag == 0)
					dflag = 1;
				else
					dflag = 0;
			}
		}
	}
	if (sflag != 0 || (dflag != 0))
		return (0);
	return (1);
}

int	ft_isblank(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
