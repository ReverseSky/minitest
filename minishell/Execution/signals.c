/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:19:27 by greg              #+#    #+#             */
/*   Updated: 2024/07/29 11:55:48 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//fonction d'interuption du programme ctrl c
// pid = -1 is the case we are a promt, pid = 0 is child, pid > 0 is parent
void	ft_ctrl_c(int signum)
{
	if (g_mini.pid == -1)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_mini.ret_err = 1;
		return ;
	}
	else if (g_mini.pid > 0)
	{
		if (kill(g_mini.pid, signum) == 0)
			g_mini.ret_err = 1;
		else
			return ;
	}
	else
	{
		printf("\n");
		close (0);
		g_mini.ret_err = 1;
		exit (1);
	}
	g_mini.sig_heredoc = 0;
}

//exit du ctrl-d
void	ft_ctrl_d(int signum)
{
	if (g_mini.pid == -1)
	{
		printf("exit\n");
		g_mini.ret_err = 1;
		exit(1);
	}
	else if (g_mini.pid > 0)
	{
		if (kill(g_mini.pid, signum) == 0)
			g_mini.ret_err = 0;
		else
			return ;
	}
	else
	{
		g_mini.ret_err = 0;
		exit(0);
	}
	g_mini.sig_heredoc = 0;
}

//ctrl\ fonction quit
void	ft_ctrl_backslash(int signum)
{
	(void)signum;
	if (g_mini.pid == -1)
	{
		rl_redisplay();
		return ;
	}
	else
	{
		printf("\e[2K");
		rl_on_new_line();
		rl_redisplay();
	}
}

void	echo_control_seq(int c)
{
	struct termios	conf;

	ioctl(ttyslot(), TIOCGETA, &conf);
	if (c == 1)
	{
		conf.c_lflag |= ECHOCTL;
		conf.c_cc[VQUIT] = 034;
	}
	else if (c == 0)
	{
		conf.c_lflag &= ~(ECHOCTL);	
		conf.c_cc[VQUIT] = 0;
	}
	ioctl(ttyslot(), TIOCSETA, &conf);
}

//numero_du_signal, procedure a faire
void	signaux(void)
{
	signal(SIGINT, ft_ctrl_c);
	signal(SIGTERM, ft_ctrl_d);
	signal(SIGQUIT, ft_ctrl_backslash);
	echo_control_seq(g_mini.in_cmd);
}
