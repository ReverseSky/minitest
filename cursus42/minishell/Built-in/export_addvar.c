/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_addvar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:17:31 by greg              #+#    #+#             */
/*   Updated: 2024/07/29 11:42:52 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//remplie la copie de NULL
static void	ft_remp(char **remp, int y)
{
	int	i;

	i = 0;
	while (remp[i] && i < y)
	{
		remp[i] = NULL;
		i++;
	}
}

//rempli la copie de exp
char	**fill_cpy(t_min *mini, char **cpy, char *str)
{
	int	i;

	i = 0;
	while (mini->c_exp[i])
		i++;
	cpy = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (mini->c_exp[i])
	{
		cpy[i] = ft_strdup(mini->c_exp[i]);
		i++;
	}
	cpy[i] = ft_strdup(str);
	cpy[i + 1] = NULL;
	return (cpy);
}

//ajoute la variable dans export
void	add_valexp(t_min *mini, char *str)
{
	char	**cpy;
	char	**new_exp;
	int		i;

	i = 0;
	cpy = NULL;
	cpy = fill_cpy(mini, cpy, str);
	new_exp = malloc(sizeof(char *) * (tablen(cpy) + 2));
	i = tablen(cpy);
	ft_remp(new_exp, i);
	new_exp = order_exp(new_exp, cpy);
	free_tab(cpy);
	free_tab(mini->c_exp);
	mini->c_exp = ft_cpytab(new_exp);
	free_tab(new_exp);
}

//ajoute une var sur la derniere ligne d'env
void	add_valenv(t_min *mini, char *str)
{
	int		i;
	char	**cpy;

	i = 0;
	while (mini->c_env[i])
		i++;
	cpy = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (mini->c_env[i])
	{
		cpy[i] = ft_strdup(mini->c_env[i]);
		i++;
	}
	cpy[i] = ft_strdup(str);
	cpy[i + 1] = NULL;
	free_tab(mini->c_env);
	mini->c_env = ft_cpytab(cpy);
	free_tab(cpy);
}
