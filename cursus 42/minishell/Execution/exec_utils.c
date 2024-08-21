/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:19:07 by greg              #+#    #+#             */
/*   Updated: 2024/07/29 11:42:57 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//recupe path pour fonction recup_path
char	*recup_pathexec(t_min *mini)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (mini->c_env[i])
	{
		if (ft_strncmp(mini->c_env[i], "PATH=", 5) == 0)
		{
			tmp = ft_strdup(mini->c_env[i] + 5);
			break ;
		}
		i++;
	}
	return (tmp);
}

int	verif_cmd(char **all_path, char **pathcmd, char **cmd)
{
	char	*gd_path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (all_path[i])
	{
		gd_path = ft_strjoin(all_path[i], pathcmd[0]);
		if (access(gd_path, R_OK) == 0)
		{
			free(gd_path);
			return (0);
		}
		else
			j++;
		free(gd_path);
		i++;
	}
	if (j == i)
		return (aff_errcmd(cmd));
	return (0);
}

// display error msg
int	aff_errcmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[0][i])
	{
		if (cmd[0][i] == '/')
		{
			ft_print_error_msg3("minishell: ", cmd[0],
				": No such file or directory\n");
			g_mini.ret_err = 127;
			return (g_mini.ret_err);
		}
		i++;
	}
	ft_print_error_msg3("minishell: ", cmd[0], ": command not found\n");
	g_mini.ret_err = 127;
	return (g_mini.ret_err);
}
