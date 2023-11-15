/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:15:44 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/09 00:08:09 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_env(void)
{
	data()->env_size = 0;
	int	i;

	i = 0;
	while (i < MAX_ENV)
	{
		data()->copy_env[i] = NULL;
		i++;
	}
}

void	copy_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		data()->copy_env[i] = ft_strdup(env[i]);
		i++;
	}
	data()->env_size = i;
}
