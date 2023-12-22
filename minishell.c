/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:18:39 by gsilva            #+#    #+#             */
/*   Updated: 2023/12/22 17:43:12 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

t_data	*data(void);
void	clean_struct(void);

t_data	*data(void)
{
	static t_data	_data;

	return (&_data);
}

int	main(int ac, char **av, char **env)
{
	char	*input;

	start_minishell(ac, av, env);
	while (1)
	{
		sig(0);
		input = readline("minishell~> ");
		if (!input)
			break ;
		if (!*input)
			continue ;
		add_history(input);
		if (lexer(input))
			executor();
	}
	clean_env();
	printf("exit\n");
	return (0);
}

void	start_minishell(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	copy_env(env);
	data()->exit_status = 0;
}
