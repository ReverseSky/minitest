/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:25:23 by grobledo          #+#    #+#             */
/*   Updated: 2024/07/31 10:33:51 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	create_oldpwd(t_min *mini)
{
	char	*tmp;
	char	*tmp2;
	char	*oldpwd;

	tmp = "OLD";
	tmp2 = recup_pwd(mini->c_env);
	oldpwd = ft_strjoin(tmp, tmp2);
	add_valenv(mini, oldpwd);
}

int	check_oldpwd(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "OLDPWD=", 7) == 0)
			return (1);
		i++;
	}
	return (0);
}
