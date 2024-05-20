/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:37:03 by iecer             #+#    #+#             */
/*   Updated: 2023/12/26 16:42:24 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_str(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			++i;
		else
		{
			++count;
			while (s[i] && s[i] != c)
				++i;
		}
	}
	return (count);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	k;

	str = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s)
		{
			str[++i] = (char *)malloc(sizeof(char) * (ft_wordlen(s, c) + 1));
			if (!str[i])
				return (ft_free_str(str));
			k = 0;
			while (*s && *s != c)
				str[i][k++] = *s++;
			str[i][k] = '\0';
		}
	}
	str[++i] = NULL;
	return (str);
}
