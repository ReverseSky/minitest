/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:19:57 by greg              #+#    #+#             */
/*   Updated: 2024/07/29 11:43:03 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*recup_rcmd(char *line)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
		i++;
	while (i != 0 && line[i] != '/')
		i--;
	tmp = malloc(sizeof(char) * ((ft_strlen(line) - i) + 1));
	i += 1;
	while (line[i])
	{
		tmp[j] = line[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

// count how many slash in the line
int	ft_nb_slash(char *line)
{
	int	i;
	int	nb_slash;

	i = 0;
	nb_slash = 0;
	while (line[i])
	{
		if (line[i] == '/')
			nb_slash += 1;
		i++;
	}
	return (nb_slash);
}

//cas /bin/echo etc + verification si l'arg avant est une cmd existante
char	*check_cmd(char *line)
{
	char	*real_cmd;
	int		nb_slash;

	nb_slash = ft_nb_slash(line);
	real_cmd = NULL;
	if (nb_slash >= 2)
	{
		if (line[0] == '/')
		{
			if (access(line, R_OK) == 0)
				real_cmd = recup_rcmd(line);
			else
			{
				perror(NULL);
				real_cmd = NULL;
			}
		}
	}
	else if (nb_slash < 2)
		real_cmd = ft_strdup(line);
	return (real_cmd);
}
