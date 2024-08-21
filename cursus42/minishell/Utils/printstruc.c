/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstruc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:22:26 by greg              #+#    #+#             */
/*   Updated: 2024/07/29 11:43:32 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// print what is inside the t_cmd struct
void	printstruc(t_cmd *cmd)
{
	int	i;

	i = 0;
	printf("\nlist of in-redirections\n");
	while (cmd->stdin[i])
	{
		printf("[%s] -> [%s]\n", cmd->stdin[i], cmd->stdin[i + 1]);
		i += 2;
	}
	i = 0;
	printf("list of out-redirections\n");
	while (cmd->stdout[i])
	{
		printf("[%s] -> [%s]\n", cmd->stdout[i], cmd->stdout[i + 1]);
		i += 2;
	}
	i = 0;
	printf("list of cmd and arg\n");
	while (cmd->cmd[i])
	{
		printf("[%s] ", cmd->cmd[i]);
		i++;
	}
	printf("\n");
}

// print what is inside the t_cmd struct
void	printstruc2(t_cmd **cmd)
{
	int	i;

	i = 0;
	printf("\nlist of all the instructions\n");
	if (!cmd)
	{
		printf("no cmd\n");
		return ;
	}
	if (!cmd[0]->stdin || !cmd[0]->stdout || !cmd[0]->cmd)
	{
		printf("struct empty\n");
		return ;
	}
	while (cmd[i])
	{
		printf("********** instruction[%d] **********\n", i);
		printstruc(cmd[i]);
		i++;
	}
	printf("********** the end **********\n");
}
