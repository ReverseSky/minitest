/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:20:54 by greg              #+#    #+#             */
/*   Updated: 2024/07/29 11:43:19 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// set g_mini.sig_heredoc at 0
int	ft_set_sig_heredoc_zero(void)
{
	g_mini.sig_heredoc = 0;
	return (0);
}

//5 fonctions
// managing heredoc + 25lignes
int	heredoc(char *cond)
{
	char	*line;
	int		pp[2];

	pipe(pp);
	while (g_mini.sig_heredoc == 1)
	{
		line = readline("> ");
		if (line == NULL)
			return (ft_set_sig_heredoc_zero());
		if (ft_strncmp(cond, line, ft_strlen(line)) == 0)
		{
			free(line);
			close(pp[1]);
			return (pp[0]);
		}
		write(pp[1], line, ft_strlen(line));
		write(pp[1], "\n", 1);
		free(line);
		g_mini.rl_done = 1;
	}
	if (g_mini.sig_heredoc == 0)
		exit(g_mini.ret_err);
	return (pp[0]);
}

// count how many heredoc
int	ft_nb_heredoc(t_cmd **cmd)
{
	int	i;
	int	j;
	int	nb_heredoc;

	i = 0;
	nb_heredoc = 0;
	while (cmd[i])
	{
		j = 0;
		while (cmd[i]->stdin[j])
		{
			if (ft_strcmp(cmd[i]->stdin[j], "<<") == 0)
				nb_heredoc++;
			j++;
		}
		i++;
	}
	return (nb_heredoc);
}

// return the name of the file and an error message if can't open
void	ft_what_file(char *file, char **resu)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		g_mini.ret_err = 1;
		exit (1);
	}
	else
		close(fd);
	if (*resu)
		free(*resu);
	*resu = ft_strdup(file);
	return ;
}

// return the name of the last file_in from simple redirection <
char	*ft_last_single_redir_in(t_cmd **cmd)
{
	int		i;
	int		j;
	char	*resu;

	i = 0;
	resu = NULL;
	while (cmd[i])
	{
		j = 0;
		while (cmd[i]->stdin[j])
		{
			if (ft_strcmp(cmd[i]->stdin[j], "<") == 0)
			{
				if (cmd[i]->stdin[j + 1])
					ft_what_file(cmd[i]->stdin[j + 1], &resu);
			}
			j++;
		}
		i++;
	}
	return (resu);
}
