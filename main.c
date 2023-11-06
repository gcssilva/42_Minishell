/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:18:39 by gsilva            #+#    #+#             */
/*   Updated: 2023/11/06 18:13:53 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

t_data	*data(void)
{
	static t_data	_data;
	
	return(&_data);
}

int	main(void)
{
	char	*a;

	while(1)
	{
		a = readline("minishell:");
		parse_input(a);
		free(a);
	}
}
