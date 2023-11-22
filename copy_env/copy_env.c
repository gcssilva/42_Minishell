/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:15:44 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/21 15:46:48 by gmorais-         ###   ########.fr       */
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
	data()->copy_env = malloc(sizeof(char *) * (i + 1));
	while (++j < i)
		data()->copy_env[j] = ft_strdup(input[j]);
	data()->copy_env[j] = NULL;
}
