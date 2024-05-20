/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:20:08 by iecer             #+#    #+#             */
/*   Updated: 2023/12/25 12:04:07 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*pf;

	pf = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			pf = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)pf);
}
