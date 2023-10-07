/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:21:34 by gmorais-          #+#    #+#             */
/*   Updated: 2023/10/07 13:24:19 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*getcwd apanha o diretorio/arquivo que estamos a utilizar
	(algo parecido com isso)*/

void	func_pwd(int fd)
{
	char	*path;
	
	path = getcwd(NULL, 1025);
	if (path == NULL)
	{
		ft_putstr_fd("Error: ", fd);
		ft_putstr_fd(strerror(errno), fd);
		ft_putstr_fd("\n", fd);
		free(path);
	}
	else
	{
		ft_putstr_fd(path, fd);
		ft_putstr_fd("\n", fd);
		free(path);
	}
}