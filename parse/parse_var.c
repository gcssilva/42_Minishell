/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:01:00 by gsilva            #+#    #+#             */
/*   Updated: 2023/12/20 15:25:37 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*copy_var(char *cmd, char *var);
char	*get_var(char *cmd, char *var);
char	*exp_var(char *cmd, char *input, int *i);
char	*exp_exs(char *cmd);

char	*copy_var(char *cmd, char *var)
{
	int		i;

	i = 0;
	while (var[i] != '=')
		i++;
	while (var[++i])
		cmd = cjoin(cmd, var[i]);
	return (cmd);
}

char	*get_var(char *cmd, char *var)
{
	int	i;

	i = -1;
	while (data()->copy_env[++i])
	{
		if (!ft_strncmp(var, data()->copy_env[i], ft_strlen(var)))
		{
			if (data()->copy_env[i][ft_strlen(var)] == '=')
			{
				cmd = copy_var(cmd, data()->copy_env[i]);
				break ;
			}
		}
	}
	return (cmd);
}

char	*exp_var(char *cmd, char *input, int *i)
{
	char	*var;

	var = 0;
	*i += 1;
	if (input[*i] == '?')
		return (exp_exs(cmd));
	while (ft_isalnum(input[*i]) || input[*i] == '_')
		var = cjoin(var, input[(*i)++]);
	*i -= 1;
	if (!var)
		cmd = cjoin(cmd, '$');
	else
		cmd = get_var(cmd, var);
	if (cmd)
		return (cmd);
	return (ft_strdup(""));
}

char	*exp_exs(char *cmd)
{
	int		i;
	char	*e_s;

	i = -1;
	e_s = ft_itoa(data()->exit_status);
	while (e_s[++i])
		cmd = cjoin(cmd, e_s[i]);
	free(e_s);
	return(cmd);
}