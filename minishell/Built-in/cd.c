/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:16:53 by greg              #+#    #+#             */
/*   Updated: 2024/07/29 20:20:59 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//change la valeur de pwd
void	change_value_pwd(char **str)
{
	char	*new_val;
	int		i;
	int		j;
	int		w;

	i = 0;
	j = 0;
	w = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "PWD=", 4) == 0)
			break ;
		i++;
	}
	j = recup_new_pwd(str);
	new_val = malloc(sizeof(char) * (j + 1));
	while (str[i][w] && w < j)
	{
		new_val[w] = str[i][w];
		w++;
	}
	new_val[w] = '\0';
	free(str[i]);
	str[i] = verif_pwd(new_val);
	free(new_val);
}

//change la valeur de oldpwd
void	change_value_oldpwd(char **str, char *pwd, char *oldpwd)
{
	char	*name_var;
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (oldpwd[y] != '=')
		y++;
	name_var = malloc(sizeof(char) * (y + 2));
	while (i <= y)
	{
		name_var[i] = oldpwd[i];
		i++;
	}
	name_var[i] = '\0';
	cpy_value(name_var, str, pwd);
	free(name_var);
}

//modifie env (pwd et oldpwd) en fonction du path donné
void	change_value_env(t_min *mini, char **cmd)
{
	char	*pwd;
	char	*oldpwd;

	pwd = recup_pwd(mini->c_env);
	oldpwd = recup_oldpwd(mini->c_env);
	if (cmd[1][0] == '/')
		change_val(mini->c_env, cmd[1], pwd, oldpwd);
	else if (ft_strcmp(cmd[1], ".") == 0 || ft_strcmp(cmd[1], "./")
		== 0)
		change_value_oldpwd(mini->c_env, pwd, oldpwd);
	else if (ft_strcmp(cmd[1], "..") == 0 || ft_strcmp(cmd[1],
			"../") == 0)
	{
		change_value_pwd(mini->c_env);
		change_value_oldpwd(mini->c_env, pwd, oldpwd);
	}
	else if ((ft_strcmp(cmd[1], "./") > 0 || ft_strcmp(cmd[1],
				"../") > 0))
	{
		change_value_oldpwd(mini->c_env, pwd, oldpwd);
		change_val_pwdpath(mini->c_env, cmd);
	}
	free(pwd);
	free(oldpwd);
}

//modifie exp (pwd et oldpwd) en fonction du path donné
void	change_value_exp(t_min *mini, char **cmd)
{
	char	*pwd;
	char	*oldpwd;

	pwd = recup_pwd(mini->c_exp);
	oldpwd = recup_oldpwd(mini->c_exp);
	if (cmd[1][0] == '/')
		change_val(mini->c_exp, cmd[1], pwd, oldpwd);
	else if (ft_strcmp(cmd[1], ".") == 0 || ft_strcmp(cmd[1], "./")
		== 0)
		change_value_oldpwd(mini->c_exp, pwd, oldpwd);
	else if (ft_strcmp(cmd[1], "..") == 0 || ft_strcmp(cmd[1],
			"../") == 0)
	{
		change_value_pwd(mini->c_exp);
		change_value_oldpwd(mini->c_exp, pwd, oldpwd);
	}
	else if (ft_strcmp(cmd[1], "./") > 0
		|| ft_strcmp(cmd[1], "../") > 0)
	{
		change_value_oldpwd(mini->c_exp, pwd, oldpwd);
		change_val_pwdpath(mini->c_exp, cmd);
	}
	free(pwd);
	free(oldpwd);
}

//redirige vers les fonctions adéquates
void	cd(t_min *mini, char **cmd)
{
	if (cmd[1] == NULL || (cmd[1][0] == '~'
		&& cmd[1][1] == '\0'))
		cd_noarg(mini);
	else if (cmd[1][0] == '~')
		change_valcdtild(mini, cmd);
	else if (chdir(cmd[1]) == -1)
	{
		aff_err(cmd);
		mini->ret_err = 1;
	}
	else
	{
		change_value_env(mini, cmd);
		change_value_exp(mini, cmd);
		mini->ret_err = 0;
	}
}

void create_oldpwd(t_min *mini)
{
	char	*tmp;
	char	*tmp2;
	char	*oldpwd;

	tmp = "OLD";
	tmp2 = recup_pwd(mini->c_env);
	oldpwd = ft_strjoin(tmp, tmp2);
	add_valenv(mini, oldpwd);
}
