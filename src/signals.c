/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:10:19 by gsilva            #+#    #+#             */
/*   Updated: 2024/01/03 17:31:24 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	sig(int flag);
void	handle_sig(int sig);
void	handle_fork_sig(int sig);
void	fork_heredoc(int sig);
void	fork_hd_2(int sig);

void	sig(int flag)
{
	if (!flag)
		signal(SIGINT, handle_sig);
	else if (flag == 1)
		signal(SIGINT, handle_fork_sig);
	else if (flag == 2)
		signal(SIGINT, fork_heredoc);
	else
		signal(SIGINT, fork_hd_2);
	signal(SIGQUIT, SIG_IGN);
}

void	handle_sig(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handle_fork_sig(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	fork_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		clean_all();
		exit(130);
	}
}

void	fork_hd_2(int sig)
{
	if (sig == SIGINT)
		data()->sig_flag = 1;
}
