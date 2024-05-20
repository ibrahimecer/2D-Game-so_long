/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:24:09 by iecer             #+#    #+#             */
/*   Updated: 2023/12/26 17:08:38 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ldst;
	size_t	k;

	ldst = 0;
	k = 0;
	while (dst[ldst] != '\0')
		++ldst;
	if (dstsize)
	{
		while (src[k] != '\0' && (k + ldst < dstsize - 1))
		{
			dst[ldst + k] = src[k];
			++k;
		}
	}
	dst[ldst + k] = '\0';
	while (src[k])
		++k;
	if (dstsize < ldst)
		return (dstsize + k);
	return (ldst + k);
}
