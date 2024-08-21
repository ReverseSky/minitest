/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:16:30 by greg              #+#    #+#             */
/*   Updated: 2024/07/29 11:42:34 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//verifie si la var PWD est vide (cd)
char	*verif_pwd(char *line)
{
	char	*tmp;

	if (ft_strcmp(line, "PWD=") == 0)
		tmp = ft_strjoin(line, "/");
	else
		tmp = ft_strdup(line);
	return (tmp);
}

//verifie si espace dans nom de variable(export)
int	verif_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (str[i] == 32)
			return (1);
		i++;
	}
	return (0);
}

//recup le nom de la variable(export_change_val)
char	*get_namevar(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	while (str[i] && str[i] != '=')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

//modifie line et tmp
char	*get_tmp(char *line, char cotes)
{
	char	*tmp;
	char	*tmp2;

	tmp = changecotesline(line, cotes);
	tmp2 = ft_strdup(tmp);
	free(tmp);
	tmp = rm_cotes(tmp2, cotes);
	return (tmp);
}
