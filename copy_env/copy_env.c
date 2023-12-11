/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:15:44 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/11 17:07:14 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	asci_ord(char **input,  int len)
{
	int	i;
	int	j;
	char	*temp;
	
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
	asci_ord(data()->ord_env, i);
}
