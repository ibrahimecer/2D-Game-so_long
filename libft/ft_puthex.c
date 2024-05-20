/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:01:28 by iecer             #+#    #+#             */
/*   Updated: 2024/01/12 12:01:28 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putuphex(unsigned int number)
{
	int	len;
	int	var;

	len = 0;
	if (number > 15)
	{
		var = ft_putuphex(number / 16);
		if (var == -1)
			return (-1);
		len += var;
	}
	if (write(1, &"0123456789ABCDEF"[number % 16], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putdownhex(unsigned int number)
{
	int	len;
	int	var;

	len = 0;
	if (number > 15)
	{
		var = ft_putdownhex(number / 16);
		if (var == -1)
			return (-1);
		len += var;
	}
	if (write(1, &"0123456789abcdef"[number % 16], 1) == -1)
		return (-1);
	return (len + 1);
}
