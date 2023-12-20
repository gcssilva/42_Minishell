/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:21:34 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/20 14:29:51 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	func_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 1025);
	if (path == NULL)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putendl_fd(strerror(errno), 2);
		free(path);
	}
	else
	{
		ft_putendl_fd(path, 1);
		free(path);
	}
}
