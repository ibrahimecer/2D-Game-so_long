/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:37:21 by iecer             #+#    #+#             */
/*   Updated: 2023/12/25 12:02:56 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len > i)
	{
		k = 0;
		while (haystack[i + k] == needle[k] && needle[k] && len > i + k)
			++k;
		if (k == ft_strlen(needle))
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
