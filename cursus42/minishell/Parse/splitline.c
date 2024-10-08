/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:21:34 by greg              #+#    #+#             */
/*   Updated: 2024/07/29 11:43:25 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// main loop of spliter
char	**spliter_loop(char **resu, char *temp)
{
	int		inb;
	int		j;
	int		k;

	inb = 0;
	j = 0;
	k = 0;
	while (g_mini.line[j])
	{
		if (is_single_pipe(j) == 1)
		{
			resu[inb++] = ft_strdup(temp);
			k = 0;
		}
		else
		{
			temp[k] = g_mini.line[j];
			temp[++k] = '\0';
		}
		j++;
	}
	resu[inb] = ft_strdup(temp);
	resu[inb + 1] = NULL;
	return (resu);
}

// cut the line received from readline, the separator are real pipes 
char	**spliter(void)
{
	char	**resu;
	char	*temp;

	resu = NULL;
	temp = NULL;
	if (iscotevalid(g_mini.line) == 0)
	{
		write(2, "minishell: quote not closed\n", 28);
		g_mini.ret_err = 1;
		return (NULL);
	}
	g_mini.nb_cmd = count_instruct(g_mini.line);
	resu = ft_test(ft_calloc(g_mini.nb_cmd + 1, sizeof(*resu)), NULL);
	temp = ft_test(ft_calloc(ft_strlen(g_mini.line) + 1, sizeof(*temp)), NULL);
	resu = spliter_loop(resu, temp);
	free(temp);
	return (resu);
}
