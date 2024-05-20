/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:01:07 by iecer             #+#    #+#             */
/*   Updated: 2024/01/12 12:01:07 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putptr(unsigned long number, int i)
{
	int	len;
	int	temp;

	len = 0;
	if (i == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		i = 0;
		len += 2;
	}
	if (number >= 16)
	{
		temp = ft_putptr(number / 16, i);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (write(1, &"0123456789abcdef"[number % 16], 1) == -1)
		return (-1);
	return (len + 1);
}
