/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmsg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:22:07 by greg              #+#    #+#             */
/*   Updated: 2024/07/29 11:43:30 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// print error message on fd = 2 with 3 char *
void	ft_print_error_msg3(char *s1, char *s2, char *s3)
{
	write(2, s1, ft_strlen(s1));
	write(2, s2, ft_strlen(s2));
	write(2, s3, ft_strlen(s3));
}

// print error message on fd = 2 for export
void	ft_export_error_msg(char *s1, char *s2)
{
	write(2, "minishell: ", 11);
	write(2, s1, ft_strlen(s1));
	write(2, ": `", 3);
	write(2, s2, ft_strlen(s2));
	write(2, "': not a valid identifier\n", 26);
}

int	verif_line(char *line)
{
	if (ft_strncmp(line, "export \"\"", ft_strlen("export \"\"")) == 0
		|| ft_strncmp(line, "export \'\'", ft_strlen("export \'\'")) == 0)
		return (1);
	else if (ft_strncmp(line, "unset \"\"", ft_strlen("unset \"\"")) == 0
		|| ft_strncmp(line, "unset \'\'", ft_strlen("unset \'\'")) == 0)
	{
		printf("minishell: unset: `' not a valid identifier\n");
		g_mini.ret_err = 1;
		return (1);
	}
	return (0);
}
