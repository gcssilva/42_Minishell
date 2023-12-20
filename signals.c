/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:10:19 by gsilva            #+#    #+#             */
/*   Updated: 2023/12/20 14:35:00 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void	sig(int flag);
void	handle_sig(int sig);
void	handle_fork_sig(int sig);

void	sig(int flag)
{
	if (!flag)
		signal(SIGINT, handle_sig);
	else if (flag == 1)
		signal(SIGINT, handle_fork_sig);
	signal(SIGQUIT, SIG_IGN);
}

void	handle_sig(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handle_fork_sig(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}
