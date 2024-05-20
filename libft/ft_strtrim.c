/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:29:37 by iecer             #+#    #+#             */
/*   Updated: 2023/12/25 17:10:51 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_control(const char c1, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c1)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_control(s1[start], set))
		++start;
	end = ft_strlen(s1);
	while (end > start && ft_control(s1[end - 1], set))
		--end;
	str = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[i] = s1[start];
		++i;
		++start;
	}
	str[i] = '\0';
	return (str);
}
