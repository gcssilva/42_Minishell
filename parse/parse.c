/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:47:01 by gsilva            #+#    #+#             */
/*   Updated: 2023/11/06 18:27:34 by gsilva           ###   ########.fr       */
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

char	*cjoin(char **str, char c)
{
	char	*new_str;
	int		i;
	size_t	len;

	if (!*str)
	{
		new_str = (char *)malloc(2 * sizeof(char));
		new_str[0] = c;
		new_str[1] = 0;
	}
	else
	{
		len = ft_strlen(*str);
		new_str = (char *)malloc((len + 2) * sizeof(char));
		i = -1;
		while (*str[++i])
			new_str[i] = *str[i];
		new_str[i] = c;
		new_str[i + 1] = 0;
		free(*str);
	}
	return(new_str);
}

void	create_struct(void)
{
	int	cmds;
	
	cmds = data()->n_cmd;
	data()->cmds = (char **)malloc(sizeof(char *) * (cmds + 1));
	data()->args = (char **)malloc(sizeof(char *) * (cmds + 1));
	while (cmds >= 0)
	{
		data()->cmds[cmds] = 0;
		data()->args[cmds] = 0;
	}
}

void	split_cmd(char *str, int j)
{
	int	i;

	i = 0;
	while(str[i] && str[i] != 32 && (str[i] < 9 || str[i] > 13))
		i++;
	data()->cmds[j] = ft_substr(str, 0, i);
	if (str[i])
		data()->args[j] = ft_substr(str, i + 1, (ft_strlen(str) - (i + 1)));
	else
	{
		data()->args[j] = (char *)malloc(sizeof(char));
		data()->args[j][0] = 0;
	}
}

void	quote_join(char **cmd, char *input, int *i)
{
	cjoin(&*cmd, input[*i]);
	while (input[++*i])
	{
		if (input[*i] == '\\' && input[*i + 1] == '"')
			cjoin(&*cmd, input[++*i]);
		else if (input[*i] == '"' && input[*i - 1] != '\\')
			break ;
		else
			cjoin(&*cmd, input[*i]);
	}
	cjoin(&*cmd, '"');
}

void	parse_input(char *input)
{
	int		i;
	int		c;
	int		flag;
	char	*cmd;

	i = 0;
	c = -1;
	cmd = 0;
	n_cmds(input);
	create_struct();
	if (!check_quotes(input))
		return ;
	while(input[i] && ((input[i] >= 9 && input[i] <= 13) || input[i] == 32))
		i++;
	while (input[i])
	{
		flag = 0;
		while(input[i] && ((input[i] >= 9 && input[i] <= 13) || input[i] == 32))
		{
			i++;
			flag = 1;
		}
		if (flag == 1 && input[i] && input[i] != '|')
			cjoin(&cmd, ' ');
		if (input[i] == '\\')
			cjoin(*cmd, input[++i]);
		else if (input[i] == '$')
			exp_var(cmd, input, &i);
		else if (input[i] == '"')
			quote_join(&cmd, input, &i);
		else if (input[i] == '\'')
			squote_join(cmd, input, &i);
		else if (input[i] == '|')
			split_cmd(cmd, ++c);
		else
			cjoin(&cmd, input[i]);
	}
	c = -1;
	while (data()->cmds[++c])
		printf("%s\n%s\n\n", data()->cmds[c], data()->args[c]);
}
