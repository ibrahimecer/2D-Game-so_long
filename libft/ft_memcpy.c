/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:10:48 by iecer             #+#    #+#             */
/*   Updated: 2023/12/25 17:07:46 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*psrc;
	char		*pdst;
	size_t		i;

	i = 0;
	pdst = (char *)dst;
	psrc = (const char *)src;
	if (!src && !dst)
		return (0);
	while (n--)
	{
		pdst[i] = psrc[i];
		++i;
	}
	return ((void *)pdst);
}
