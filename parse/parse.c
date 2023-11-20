/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:47:01 by gsilva            #+#    #+#             */
/*   Updated: 2023/11/20 17:29:38 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
	return(new_str);
}

int	split_cmd(char *str, int flag)
{
	static int	c = 0;
	static int	a = 0;

	if (str && str[0])
	{
		data()->cmds[c].arg[a++] = ft_strdup(str);
		if (a == 1)
		{
			data()->cmds[c].cmd = ft_strdup(str);
			data()->cmds[c].index = c + 1;
		}
		free(str);
		str = 0;
	}
	if (flag == 0)
	{
		c = 0;
		a = 0;
	}
	else if (flag == 124)
	{
		c++;
		a = 0;
	}
	return (c);
}

char	*quote_join(char *cmd, char *input, int *i)
{
	int	q;
	char *new_cmd;

	q = input[*i];
	new_cmd = 0;
	while (input[++*i] != '"')
	{
		if (q == '"' && input[*i] == '$')
			exp_var(cmd, input, i);
		else
			new_cmd = cjoin(new_cmd, input[*i]);
	}
	if (!new_cmd)
		return (0);
	new_cmd = add_to_str(cmd, new_cmd);
	if (cmd)
	{
		free(cmd);
		cmd = 0;
	}
	return (new_cmd);
}

void	copy_var(char *cmd, char *var)
{
	int	i;

	i = 0;
	while (var[i] != '=')
		i++;
	while (var[++i])
		cmd = cjoin(cmd, var[i]);
}

void	exp_var(char *cmd, char *input, int *i)
{
	int		j;
	char	var[1000];

	j = 0;
	*i += 1;
	while(ft_isalnum(input[*i]) || input[*i] == '_')
		var[j++] = input[*i++];
	if (j == 0)
		cmd = cjoin(cmd, '$');
	else
	{
		j = -1;
		while(data()->copy_env[++j])
		{
			if (!ft_strncmp(var, data()->copy_env[j], ft_strlen(var)))
			{
				if (data()->copy_env[j][ft_strlen(var)] == '=')
				{
					copy_var(cmd, data()->copy_env[j]);
					break ;
				}
			}
		}
	}
}

int	get_pos(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
		i++;
	return (i);
}

void	write_redir(char *r_file, int r)
{
	int	i;

	i = split_cmd(0, 1);
	if (r == 120)
		data()->cmds[i].delimiters[get_pos(data()->cmds[i].delimiters)] = ft_strdup(r_file);
	else
	{
		data()->cmds[i].red[get_pos(data()->cmds[i].red)] = ft_strdup(r_file);
		if (r == 60)
			data()->cmds[i].order[get_pos(data()->cmds[i].order)] = ft_strdup("in");
		else if (r == 62)
			data()->cmds[i].order[get_pos(data()->cmds[i].order)] = ft_strdup("out");
		else
			data()->cmds[i].order[get_pos(data()->cmds[i].order)] = ft_strdup("ap");
	}
}

void	add_redir(char *input, int *i)
{
	int		r;
	char	*r_file;

	r = input[*i];
	r_file = 0;
	if (input[++*i] == r)
	{
		r += r;
		*i += 1;
	}
	while (ft_isblank(input[*i]))
		*i += 1;
	while (input[*i] && input[*i] != '|' && !ft_isblank(input[*i]) && !ft_isredir(input[*i]))
	{
		if (input[*i] == '"' || input[*i] == '\'')
			r_file = quote_join(r_file, input, i);
		else if (input[*i] == '$')
			exp_var(r_file, input, i);
		else
			r_file = cjoin(r_file, input[*i]);
		*i += 1;
	}
	write_redir(r_file, r);
	free (r_file);
}

void	parse_input(char *input)
{
	int		i;
	char	*cmd;

	i = -1;
	cmd = 0;
	while(input[++i])
	{
		if (input[i] == '|' || ft_isblank(input[i]) || ft_isredir(input[i]))
		{
			split_cmd(cmd, input[i]);
			if (ft_isredir(input[i]))
				add_redir(input, &i);
			cmd = 0;
		}
		else if (input[i] == '$')
			exp_var(cmd, input, &i);
		else if (input[i] == '"' || input[i] == '\'')
			cmd = quote_join(cmd, input, &i);
		else
			cmd = cjoin(cmd, input[i]);
	}
	split_cmd(cmd, 0);
}
