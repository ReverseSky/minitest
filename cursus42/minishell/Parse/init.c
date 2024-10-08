/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:20:26 by greg              #+#    #+#             */
/*   Updated: 2024/07/31 10:38:44 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//affiche erreur
void	aff_err(char **cmd)
{
	if (check_arg(cmd[1]) == 1)
	{
		ft_print_error_msg3("minishell: cd: ", cmd[1], ": Not a directory\n");
		g_mini.ret_err = 1;
	}
	else
	{
		ft_print_error_msg3("minishell: cd: ", cmd[1],
			": No such file or directory\n");
		g_mini.ret_err = 1;
	}
}

//initialise la structure
void	init_struct(t_min *mini, char **envp)
{
	if (envp[0] == NULL)
	{
		printf("only getpwd & oldpwd\n");
	}
	else
		mini->c_env = ft_cpytab(envp);
	init_export(mini);
	mini->line = NULL;
	mini->prompt = "minishell> ";
	mini->val_home = recup_valhome(mini->c_env);
	mini->ret_err = 0;
	mini->nb_passage_exp = 0;
	mini->sig_heredoc = 1;
	mini->rl_done = 0;
	mini->in_cmd = 0;
	mini->pid = -1;
}

//creer la copie d'export au tout début
void	init_export(t_min *mini)
{
	if (check_oldpwd(mini->c_env) == 0)
		create_oldpwd(mini);
	mini->c_exp = init_exp(mini->c_env);
	mini->c_exp = order_exp(mini->c_exp, mini->c_env);
}

//free les tableaux etc
void	free_all(t_min mini)
{
	free_tab(mini.c_env);
	free_tab(mini.c_exp);
	free(mini.val_home);
}

//recup valeur home pour cd et ~
char	*recup_valhome(char	**c_env)
{
	char	*tmp;
	int		i;
	int		j;
	int		y;

	i = 0;
	j = 0;
	y = 0;
	while (c_env[i++])
	{
		if (ft_strncmp(c_env[i], "HOME=", 5) == 0)
			break ;
	}
	tmp = malloc(sizeof(char) * (ft_strlen(c_env[i]) + 1));
	while (c_env[i][j] != '=')
		j++;
	j += 1;
	while (c_env[i][j])
	{
		tmp[y] = c_env[i][j];
		j++;
		y++;
	}
	tmp[y] = '\0';
	return (tmp);
}
