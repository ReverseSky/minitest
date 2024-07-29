/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitcmd_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:21:16 by greg              #+#    #+#             */
/*   Updated: 2024/07/29 11:43:22 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//1 fonctions
//remove all the multiple char to keep only one or none if remove_both_char=1
char	*remove_double_char(char *line, char c, int remove_both_char)
{
	char	*resu;
	int		i;
	int		j;

	i = ft_strlen(line) + 1;
	resu = ft_test(ft_calloc(i, sizeof(*resu)), NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (!(line[i] == c && line[i + 1] == c))
		{
			resu[j] = line[i];
			j++;
		}
		else if (remove_both_char)
			i++;
		i++;
	}
	return (resu);
}

//remove all the double char that are not inside quotes
char	*remove_double_char_q(char *line, char c)
{
	char	*resu;
	int		i;
	int		j;

	i = ft_strlen(line) + 1;
	resu = ft_test(ft_calloc(i, sizeof(*resu)), NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (!(line[i] == c && line[i + 1] == c) || ft_qpar(line, i) == 1)
		{
			resu[j] = line[i];
			j++;
		}
		i++;
	}
	return (resu);
}
