/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:20:58 by greg              #+#    #+#             */
/*   Updated: 2024/07/29 11:43:20 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// exit if the redirection has no arg to open
void	ft_exit_when_no_arg(void)
{
	write(2, "minishell: syntax error near unexpected token `newline'\n", 56);
	g_mini.ret_err = 258;
	exit (g_mini.ret_err);
}

// exit if the redirection has no arg to open
void	ft_exit_unexpected_token(t_cmd **cmd, int nb, int i)
{
	char	*arrow;

	arrow = ft_test(ft_calloc(3, sizeof(*arrow)), NULL);
	if (ft_strlen(cmd[nb]->stdout[i]) > 3)
		arrow = ft_strdup(">>");
	else
		arrow = ft_strdup(">");
	ft_print_error_msg3(ERR_TOKEN_SHORT, arrow, "'\n");
	free(arrow);
	g_mini.ret_err = 258;
	exit (258);
}

// return the fd of the redirection out
int	ft_redir_out(t_cmd **cmd, int nb)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	while (cmd[nb]->stdout[i])
	{
		if (cmd[nb]->stdout[i + 1] == NULL)
			ft_exit_when_no_arg();
		if (ft_strcmp(cmd[nb]->stdout[i], ">") == 0)
			fd = ft_open_file(cmd[nb]->stdout[i + 1], fd, 1);
		else if (ft_strcmp(cmd[nb]->stdout[i], ">>") == 0)
			fd = ft_open_file(cmd[nb]->stdout[i + 1], fd, 2);
		else
			ft_exit_unexpected_token(cmd, nb, i);
		i += 2;
	}
	return (fd);
}

// return type of the last redir: 0 is none, 1 is <, 2 is <<
int	ft_what_is_last_redir_in(t_cmd **cmd)
{
	int	i;
	int	j;
	int	resu;

	i = 0;
	resu = 0;
	while (cmd[i])
	{
		j = 0;
		while (cmd[i]->stdin[j])
		{
			if (ft_strcmp(cmd[i]->stdin[j], "<") == 0)
				resu = 1;
			else if (ft_strcmp(cmd[i]->stdin[j], "<<") == 0)
				resu = 2;
			j++;
		}
		i++;
	}
	return (resu);
}
