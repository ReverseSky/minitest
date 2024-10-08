/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:16:46 by greg              #+#    #+#             */
/*   Updated: 2024/07/29 11:42:44 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//verifie si un . est present dans le fichier quand chdir return 1
int	check_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

//recupere la valeur de pwd avant changement
char	*recup_pwd(char **str)
{
	char	*pwd;
	int		i;

	i = 0;
	pwd = NULL;
	while (str[i])
	{
		if (ft_strncmp(str[i], "PWD=", 4) == 0)
		{
			pwd = ft_strdup(str[i]);
			break ;
		}
		i++;
	}
	return (pwd);
}

//recupere la valeur de oldpwd avant changement
char	*recup_oldpwd(char **str)
{
	char	*oldpwd;
	int		i;

	i = 0;
	oldpwd = NULL;
	while (str[i])
	{
		if (ft_strncmp(str[i], "OLDPWD=", 7) == 0)
		{
			oldpwd = ft_strdup(str[i]);
			break ;
		}
		i++;
	}
	return (oldpwd);
}

//join nom fonction & la nouvelle valeur;
char	*join_var(char *str1, char *new_val)
{
	char	*dest;
	char	*cpy;
	int		i;
	int		j;

	j = 0;
	cpy = malloc(sizeof(char) * (ft_strlen(new_val) + 1));
	i = 0;
	while (new_val[i] != '=')
		i++;
	i += 1;
	while (new_val[i])
		cpy[j++] = new_val[i++];
	cpy[j] = '\0';
	dest = ft_strjoin(str1, cpy);
	free(cpy);
	return (dest);
}

//modifie la valeur de oldpwd
void	cpy_value(char *name_var, char **str, char *new_val)
{
	char	*ret;
	int		i;

	i = 0;
	ret = join_var(name_var, new_val);
	while (str[i])
	{
		if (ft_strncmp(str[i], name_var, ft_strlen(name_var)) == 0)
		{
			free(str[i]);
			str[i] = ft_strdup(ret);
			break ;
		}
		i++;
	}
	free(ret);
}
