/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_dollar_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:20:11 by greg              #+#    #+#             */
/*   Updated: 2024/07/31 17:28:32 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//verifie quel cas present 
int	verif_dollarcase(char *line)
{
	char	*name_var;
	int		i;

	i = 0;
	while (line[i] && line[i] != '$')
		i++;
	if (line[i + 1] == '?')
		return (1);
	else
	{
		name_var = recup_namevar(line);
		if (name_var[0] == '\0')
			return (4);
		else if (verif_var(name_var) == 0)
		{
			free(name_var);
			return (2);
		}
		else
		{
			free(name_var);
			return (3);
		}
	}
	return (0);
}

//verifie si variable existante
int	verif_var(char *name_var)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strjoin(name_var, "=");
	while (g_mini.c_env[i])
	{
		if (ft_strncmp(g_mini.c_env[i], tmp, ft_strlen(tmp)) == 0)
			break ;
		i++;
	}
	free(tmp);
	if (i == tablen(g_mini.c_env))
		return (1);
	return (0);
}

//recupere le nom de la variable (forcement un dollar)
char	*recup_namevar(char *line)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '$')
		i++;
	j = i;
	while (line[i] && line[i] != '\0' && line[i] != '$' && line[i]
		!= ' ' && line[i] != '\'' && line[i] != '"' && line[i] != '/')
		i++;
	tmp = malloc(sizeof(char) * (i - j + 5));
	i = j + 1;
	j = 0;
	while (line[i] != '\0' && line[i] != '$' && line[i] != ' '
		&& line[i] != '\'' && line[i] != '"' && line[i] != '/')
	{
		tmp[j] = line[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

//supprime le double dollar
char	*rm_d_dollar(char *tmp)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_line = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
	while (tmp[i])
	{
		if (tmp[i] == '$' && tmp[i + 1] == '$')
			i += 2;
		new_line[j] = tmp[i];
		j++;
		i++;
	}
	new_line[j] = '\0';
	return (new_line);
}

//compte le nombre de dollar
int	count_nbdollar(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '$')
			count += 1;
		i++;
	}
	return (count);
}
