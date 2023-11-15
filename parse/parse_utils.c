/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:20:31 by gsilva            #+#    #+#             */
/*   Updated: 2023/11/15 17:01:55 by gsilva           ###   ########.fr       */
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
	int	q;

	while(input[++i])
	{
		if ((input[i] == '\'' || input[i] == '"') && q == 0)
			q = input[i];
		else if ((input[i] == '\'' || input[i] == '"') && q == input[i])
			q = 0;
	}
	if (q != 0)
		return (0);
	return (1);
}

int	ft_isblank(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	exp_var(char **cmd, char *input, int *i)
{
	
}

int	check_pipes(char *input)
{
	int	i;
	int	flag;
	int	q;

	i = -1;
	flag = 0;
	while (input[++i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			q = input[i];
			flag = 1;
			while (input[++i] != q)
				continue;
		}
		if (input[i] != '|' && !ft_isblank(input[i]))
			flag = 1;
		else if (input[i] == '|')
		{
			if (flag == 1)
				flag = 0;
			else
				return (0);
		}
	}
	if (flag == 0)
		return (0);
	return (1);
}

int	lexer(char *input)
{
	if (!check_quotes(input))
	{
		err_code = 1;
		return (0);
	}
	if (!check_pipes(input))
	{
		err_code = 2;
		return (0);
	}
	return (1);
}