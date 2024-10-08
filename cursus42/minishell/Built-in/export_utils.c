/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:17:48 by greg              #+#    #+#             */
/*   Updated: 2024/07/31 17:27:00 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//retourna la taille d'un char ** 
int	tablen(char **s1)
{
	int	i;

	i = 0;
	if (!s1)
		return (1);
	else
	{
		while (s1[i])
			i++;
	}
	return (i);
}

//copie str dans new_val
char	**fill_exp(char **new_val, char *str)
{
	int	i;

	i = 0;
	while (new_val[i])
		i++;
	new_val[i] = ft_strdup(str);
	new_val[i + 1] = NULL;
	return (new_val);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = malloc(sizeof(*s1) * (i + j + 5));
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

//print export
void	print_valexp(char *str)
{
	int	index;
	int	y;

	y = 0;
	printf("declare -x ");
	while (str[y] != '=')
		printf("%c", str[y++]);
	printf("=\"");
	index = y + 1;
	if (str[y] != '\0')
		while (str[index] != '\0')
			printf("%c", str[index++]);
	printf("\"\n");
}

//print export with "declare-x" & valeur entre ""
void	print_export(char **c_exp)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (c_exp[i])
	{
		if (check_var(c_exp[i]) == 0)
		{
			printf("declare -x ");
			while (c_exp[i][y] != '\0')
				printf("%c", c_exp[i][y++]);
			printf("\n");
		}
		else
			print_valexp(c_exp[i]);
		y = 0;
		i++;
	}
}
