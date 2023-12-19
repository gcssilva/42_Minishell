/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:15:44 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/17 15:37:33 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


void	clean_env(void)
{
	int	i;

	i = -1;
	while (data()->copy_env[++i] != NULL)
		free(data()->copy_env[i]);
	i = -1;
	while (data()->ord_env[++i] != NULL)
		free(data()->ord_env[i]);
	free(data()->copy_env);
	free(data()->ord_env);
}

void	asci_ord(char **input)
{
	int		i;
	int		j;
	int		len;
	char	*temp;

	len = 0;
	while (input[len])
		len++;
	i = 0;
	while (++i < len)
	{
		temp = input[i];
		j = i - 1;
		while (j >= 0 && strcmp(input[j], temp) > 0)
		{
			input[j + 1] = input[j];
			j = j - 1;
		}
		input[j + 1] = temp;
	}
}

void	copy_env(char **input)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (input[i] != NULL)
		i++;
	data()->copy_env = (char **)malloc(sizeof(char *) * (i + 1));
	data()->ord_env = (char **)malloc(sizeof(char *) * (i + 1));
	while (++j < i)
	{
		data()->copy_env[j] = ft_strdup(input[j]);
		data()->ord_env[j] = ft_strdup(input[j]);
	}
	data()->copy_env[j] = NULL;
	data()->ord_env[j] = NULL;
	asci_ord(data()->ord_env);
}
