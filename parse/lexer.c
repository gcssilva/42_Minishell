/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:07:15 by gsilva            #+#    #+#             */
/*   Updated: 2023/12/04 19:06:49 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_pipes(char *input, int flag);
int	check_quotes(char *input);
int	lexer(char *input);

int	check_pipes(char *input, int flag)
{
	int	i;
	int	q;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			q = input[i];
			flag = 1;
			while (input[++i] != q)
				continue ;
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
	return (flag);
}

int	check_quotes(char *input)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (ft_isblank(input[i]))
		i++;
	if (!input[i])
		return (0);
	i = -1;
	while (input[++i])
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

int	lexer(char *input)
{
	if (!check_quotes(input) || !check_pipes(input, 0))
		return (0);
	return (1);
}
