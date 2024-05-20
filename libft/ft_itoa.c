/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:30:29 by iecer             #+#    #+#             */
/*   Updated: 2023/12/26 12:36:16 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digitcount(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		++i;
	while (n < 0 || n > 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	num;
	size_t	lstr;
	char	*str;

	num = (long)n;
	lstr = ft_digitcount(n);
	str = (char *)malloc(sizeof(char) * (lstr + 1));
	if (!str)
		return (NULL);
	str[lstr] = '\0';
	if (n < 0)
	{
		num = -num;
		str[0] = '-';
	}
	if (n == 0)
		str[0] = '0';
	while (num != 0)
	{
		str[--lstr] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
