/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:22:14 by iecer             #+#    #+#             */
/*   Updated: 2023/12/25 16:54:08 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*pdest;
	const char		*psrc;
	size_t			i;

	pdest = (char *)dest;
	psrc = (const char *)src;
	i = 0;
	if (!pdest && !psrc)
		return (NULL);
	if (pdest < psrc)
	{
		while (i < n)
		{
			pdest[i] = psrc[i];
			++i;
		}
	}
	else
	{
		while (n--)
		{
			pdest[n] = psrc[n];
		}
	}
	return ((void *)pdest);
}
