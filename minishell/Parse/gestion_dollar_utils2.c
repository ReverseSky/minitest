/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_dollar_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:20:15 by greg              #+#    #+#             */
/*   Updated: 2024/07/29 11:43:09 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//copy name var without ?
char	*copy_tmp(char *line, int i)
{
	char	*tmp;
	int		j;

	j = 0;
	while (line[i])
	{
		j++;
		i++;
	}
	tmp = malloc(sizeof(char) * (j + 1));
	i = 0;
	j = 0;
	while (line[i] && line[i] != '?')
		i++;
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
