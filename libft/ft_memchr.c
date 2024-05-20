/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:28:57 by iecer             #+#    #+#             */
/*   Updated: 2023/12/26 16:39:25 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*p;

	i = 0;
	p = (const char *)s;
	while (n--)
	{
		if (p[i] == (char)c)
			return ((void *)&p[i]);
		++i;
	}
	return (NULL);
}
