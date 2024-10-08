/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:22:32 by greg              #+#    #+#             */
/*   Updated: 2024/07/31 17:37:05 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	size_t			j;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	i = 0;
	j = 1;
	if (n == 0)
		return (-1);
	while (s3[i] && s4[i] && s3[i] == s4[i] && j < n)
	{
		i++;
		j++;
	}
	return (s3[i] - s4[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

//verifie que la string est que des digit
int	strdigit(char *str)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (str[y])
	{
		if (((str[0] == '-' || str[0] == '+') || (str[0] >= '0' && str[0]
					<= '9')) && (str[y] >= '0' && str[y] <= '9'))
			i++;
		y++;
	}
	if (str[0] == '-' || str[0] == '+')
	{
		if (i != (y - 1))
			return (1);
	}
	else
	{
		if (i != y)
			return (1);
	}
	return (0);
}

char    *ft_strdup(char *src)
{
    int i;
    char *dest;
    size_t len;

    i = 0;
    len = ft_strlen(src);
    dest = (char *)malloc(len + 3);
    if (!dest)
        return (NULL);
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
