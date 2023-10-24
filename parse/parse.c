/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:47:01 by gsilva            #+#    #+#             */
/*   Updated: 2023/10/24 15:29:00 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	n_cmds(char	*input)
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
	return (cmds);
}

char	*cjoin(char *str, char c)
{
	char	*new_str;
	int		i;
	size_t	len;

	if (!str)
	{
		new_str = (char *)malloc(2 * sizeof(char));
		new_str[0] = c;
		new_str[1] = 0;
	}
	else
	{
		len = ft_strlen(str);
		new_str = (char *)malloc((len + 2) * sizeof(char));
		i = -1;
		while (str[++i])
			new_str[i] = str[i];
		new_str[i] = c;
		new_str[i + 1] = 0;
		free(str);
	}
	return(new_str);
}

void	parse_input(char *input)
{
	int		i;
	int		c;
	int		a;
	char	*cmd;

	i = -1;
	c = -1;
	a = -1;
	cmd = 0;
	data()->cmds = (char **)malloc(sizeof(char *) * (n_cmds(input) + 1));
	data()->args = (char **)malloc(sizeof(char *) * (n_cmds(input) + 1));
	while (input[++i])
	{
		while((input[i] >= 9 && input[i] <= 13) || input[i] == 32)
			i++;
		while ((input[i] < 9 || input[i] > 13) && input[i] != 32)
		{
			if (input[i] == '|')
				break ;
			else if (input[i] == '"')
			{
				while(input[++i] != '"')
				{
					if (input[i] == '\\')
						i++;
					cjoin(cmd, input[i]);
				}
			}
			else if (input[i] == '\'')
			{
				while(input[++i] != '\'')
				{
					if (input[i] == '\\')
						i++;
					cjoin(cmd, input[i]);
				}
			}
			else
				cjoin(cmd, input[i]);
		}
		data()->cmds[++c] = ft_strdup(cmd);
		free(cmd);
		cmd = 0;
		if (input[i] == '|')
			break ;
		while((input[i] >= 9 && input[i] <= 13) || input[i] == 32)
			i++;
		while ((input[i] < 9 || input[i] > 13) && input[i] != 32)
		{
			if (input[i] == '|')
				break ;
			else if (input[i] == '"')
			{
				while(input[++i] != '"')
				{
					if (input[i] == '\\')
						i++;
					cjoin(cmd, input[i]);
				}
			}
			else if (input[i] == '\'')
			{
				while(input[++i] != '\'')
				{
					if (input[i] == '\\')
						i++;
					cjoin(cmd, input[i]);
				}
			}
			else
				cjoin(cmd, input[i]);
		}
		data()->args[++a] = ft_strdup(cmd);
		free(cmd);
		cmd = 0;
	}
	c = -1;
	while (data()->cmds[++c])
		printf("%s\n%s\n\n", data()->cmds[c], data()->args[c]);
}