/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:21:34 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/11 12:23:05 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*getcwd apanha o diretorio/arquivo que estamos a utilizar
	(algo parecido com isso)*/
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
