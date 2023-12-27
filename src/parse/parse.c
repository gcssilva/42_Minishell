/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:47:01 by gsilva            #+#    #+#             */
/*   Updated: 2023/12/22 18:10:00 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*cjoin(char *str, char c);
int		split_cmd(char *str, int flag);
char	*quote_join(char *cmd, char *input, int *i);
int		get_pos(char **ar);
void	parse_input(char *input);

char	*cjoin(char *str, char c)
{
	char	*new_str;
	size_t	i;
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
		while (++i < len)
			new_str[i] = str[i];
		new_str[i] = c;
		new_str[i + 1] = 0;
		free(str);
	}
	return (new_str);
}

int	split_cmd(char *str, int flag)
{
	static int	c = 0;
	static int	a = 0;

	if (str && *str)
	{
		data()->cmds[c]->arg[a++] = ft_strdup(str);
		data()->cmds[c]->arg[a] = 0;
		if (a == 1)
		{
			data()->cmds[c]->cmd = ft_strdup(str);
			data()->cmds[c]->index = c + 1;
		}
	}
	if (flag == 0 || flag == 124)
	{
		c++;
		if (flag == 0)
			c = 0;
		a = 0;
	}
	free(str);
	return (c);
}

char	*quote_join(char *cmd, char *input, int *i)
{
	int	q;

	q = input[*i];
	while (input[++*i] && input[*i] != q)
	{
		if (q == '"' && input[*i] == '$')
			cmd = exp_var(cmd, input, i);
		else
			cmd = cjoin(cmd, input[*i]);
	}
	if (!cmd)
		return (ft_strdup(""));
	return (cmd);
}

int	get_pos(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
		i++;
	return (i);
}

void	parse_input(char *input)
{
	int		i;
	char	*cmd;

	i = -1;
	cmd = 0;
	while (input[++i])
	{
		if (input[i] == '|' || ft_isblank(input[i]) || ft_isredir(input[i]))
		{
			split_cmd(cmd, input[i]);
			if (ft_isredir(input[i]))
				add_redir(input, &i);
			cmd = 0;
		}
		else if (input[i] == '$')
			cmd = exp_var(cmd, input, &i);
		else if (input[i] == '"' || input[i] == '\'')
			cmd = quote_join(cmd, input, &i);
		else
			cmd = cjoin(cmd, input[i]);
		if (input[i] == 0)
			break ;
	}
	split_cmd(cmd, 0);
}
