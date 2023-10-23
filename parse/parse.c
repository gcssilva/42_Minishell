/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:47:01 by gsilva            #+#    #+#             */
/*   Updated: 2023/10/18 17:35:16 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**add_str(char **arr, char *str)
{
	char	**new_arr;
	int		i;

	if (!str)
		return (arr);
	i = 0;
	while (arr[i])
		i++;
	new_arr = (char **)malloc((i + 2) * sizeof(char *));
	i = -1;
	while (arr[++i])
	{
		new_arr[i] = ft_strdup(arr[i]);
		free(arr[i]);
	}
	new_arr[i] = ft_strdup(str);
	new_arr[i + 1] = 0;
	free(arr);
	return (new_arr);
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

char	*add_quote(char *str, char *quote)
{
	char	*new_str;
	int		i;

	i = -1;
	while (quote[++i] && quote[i] != '\"')
		new_str = cjoin(str, quote[i]);
	free(str);
	return(new_str);
}

void	parse_input(char *input)
{
	char	**cmds;
	char	*cmd;
	int		i;

	cmds = (char **)malloc(1 * sizeof(char *));
	cmds[0] = 0;
	cmd = 0;
	i = -1;
	while (input[++i])
	{
		if (input[i] == '|')
		{
			cmds = add_str(cmds, cmd);
			free(cmd);
			cmd = 0;
		}
		else if (input[i] == '\"')
		{
			cmd = add_quote(cmd, &input[i]);
		}
		else
		{
			cmd = cjoin(cmd, input[i]);
		}
	}
	cmds = add_str(cmds, cmd);
	printf("opa fio\n");
	printf("%s\n", cmds[0]);
}
