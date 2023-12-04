/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:15:44 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/04 18:07:19 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	copy_env(char **input)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (input[i] != NULL)
		i++;
	data()->copy_env = (char **)malloc(sizeof(char *) * (i + 1));
	while (++j < i)
		data()->copy_env[j] = ft_strdup(input[j]);
	data()->copy_env[j] = NULL;
}
