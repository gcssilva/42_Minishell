/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:47:01 by gsilva            #+#    #+#             */
/*   Updated: 2023/11/13 00:23:18 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

void	split_cmd(char *str, int *flag)
{
	static int	c = -1;
	static int	a = -1;

	if (*flag == 2)
	{
		c = -1;
		a = -1;
		return ;
	}
	if (!str)
		return ;
	if (*flag == 1)
	{
		c++;
		a = -1;
		data()->cmds[c]->cmd = ft_strdup(str);
		*flag = 0;
	}
	else
		data()->cmds[c]->arg[++a] = ft_strdup(str);
}

void	quote_join(char **cmd, char *input, int *i)
{
	cjoin(&*cmd, input[*i]);
	while (input[++*i])
	{
		if (input[*i] == '\\' && input[*i + 1] == '"')
			cjoin(&*cmd, input[++*i]);
		else if (input[*i] == '$')
			exp_var(&*cmd, input, &*i);
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

	i = -1;
	flag = 1;
	while(input[++i])
	{
		if (ft_isblank(input[i]))
			split_cmd(cmd, &flag);
		else if (input[i] == '$')
			exp_var(&cmd, input, &i);
		else if (input[i] == '"')
			quote_join(&cmd, input, &i);
		else if (input[i] == '\'')
			squote_join(cmd, input, &i);
		else if (input[i] == '|')
		{
			split_cmd(cmd, &flag);
			flag = 1;
		}
		else
			cjoin(&cmd, input[i]);
	}
}
