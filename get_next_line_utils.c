/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:26:16 by tgoel             #+#    #+#             */
/*   Updated: 2022/04/14 08:31:32 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char	*ft_strdup(const char *s1, int x)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(*str) * (x + 1));
	i = 0;
	while (i < x)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strljoin(const char *s1, char const *s2, int x)
{
	char	*res;
	int		i;
	int		j;

	res = malloc((ft_strlen(s1) + x + 1));
	if (!res)
		return (NULL);
	if (!(s1 && s2))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < x)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	x;

	if (!s)
		return (0);
	x = 0;
	while (s[x])
	{
		if (s[x] == c)
			return ((char *)&s[x]);
		x++;
	}
	return (NULL);
}
