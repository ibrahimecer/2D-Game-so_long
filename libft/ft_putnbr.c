/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:01:18 by iecer             #+#    #+#             */
/*   Updated: 2024/01/12 12:01:18 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putint(int number)
{
	int	len;
	int	var;

	len = 0;
	if (number == -2147483648)
		return (write(1, "-2147483648", 11));
	if (number < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		++len;
		number *= -1;
	}
	if (number > 9)
	{
		var = ft_putint(number / 10);
		if (var == -1)
			return (-1);
		len += var;
	}
	if (write(1, &"0123456789"[number % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putunsigned(unsigned int number)
{
	int	len;
	int	var;

	len = 0;
	if (number > 9)
	{
		var = ft_putunsigned(number / 10);
		if (var == -1)
			return (-1);
		len += var;
	}
	if (write(1, &"0123456789"[number % 10], 1) == -1)
		return (-1);
	return (len + 1);
}
