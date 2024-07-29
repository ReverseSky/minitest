/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:22:44 by greg              #+#    #+#             */
/*   Updated: 2024/07/29 11:43:34 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// used in ft_strstrim
static int	ft_isinlist(char c, char *list)
{
	int	i;

	i = 0;
	while (list[i] != '\0')
	{
		if (list[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// used in ft_strstrim
static char	*ft_mallocresu(int lens1, int trimdeb, int trimfin, char *s1)
{
	char	*resu;
	int		i;

	if ((lens1 - trimdeb - trimfin) < 0)
		resu = malloc (sizeof(char));
	else
		resu = malloc ((lens1 - trimdeb - trimfin + 1) * sizeof(char));
	if (!resu)
		return (NULL);
	i = trimdeb;
	while (i < lens1 - trimfin)
	{
		resu[i - trimdeb] = s1[i];
		i++;
	}
	resu[i - trimdeb] = '\0';
	return (resu);
}	

// remove the char contained in set at the beginning aand the end os s1
char	*ft_strtrim(char *s1, char *set)
{
	int		lens1;
	int		trimdeb;
	int		trimfin;
	char	*resu;

	trimdeb = 0;
	trimfin = 0;
	if (!set || !s1)
		return (NULL);
	while (ft_isinlist(s1[trimdeb], set) == 1 && s1[trimdeb] != '\0')
		trimdeb++;
	lens1 = ft_strlen(s1);
	while (ft_isinlist(s1[lens1 - trimfin - 1], set) == 1 && trimfin < lens1)
		trimfin++;
	resu = ft_mallocresu(lens1, trimdeb, trimfin, s1);
	return (resu);
}

// malloc with 0 everywhere inside the vaiable
void	*ft_calloc(int count, int size)
{
	void	*resu;
	int		i;

	resu = malloc(count * size);
	if (!resu)
		return (0);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *)resu)[i] = 0;
		i++;
	}
	return (resu);
}

//calloc LIBFT cassandra
void	*ft_calloc2(int count, int size)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc((sizeof(char)) * ((count * size) + 1));
	if (!ptr)
		return (NULL);
	while (i < (count * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
