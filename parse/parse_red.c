/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:03:05 by gsilva            #+#    #+#             */
/*   Updated: 2023/12/04 17:50:58 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	write_redir(char *r_file, int r);
void	add_redir(char *input, int *i);

void	write_redir(char *r_file, int r)
{
	int	i;
	int	j;

	i = split_cmd(0, 1);
	j = get_pos(data()->cmds[i].red);
	data()->cmds[i].red[j] = ft_strdup(r_file);
	data()->cmds[i].red[j + 1] = 0;
	if (r == 60)
		data()->cmds[i].order[j] = ft_strdup("in");
	else if (r == 62)
		data()->cmds[i].order[j] = ft_strdup("out");
	else if (r == 120)
		data()->cmds[i].order[j] = ft_strdup("del");
	else
		data()->cmds[i].order[j] = ft_strdup("ap");
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
	while (input[*i] && input[*i] != '|'
		&& !ft_isblank(input[*i]) && !ft_isredir(input[*i]))
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
