/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:33:38 by iecer             #+#    #+#             */
/*   Updated: 2024/04/17 14:46:09 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int	ft_check(char chr)
{
	if (chr == 's' || chr == 'c' || chr == 'd' || chr == 'i' || chr == 'u'
		|| chr == 'x' || chr == 'X' || chr == 'p' || chr == '%')
		return (1);
	return (0);
}

static int	ft_format(va_list ar, char chr)
{
	if (chr == 's')
		return (ft_putstr(va_arg(ar, char *)));
	else if (chr == 'c')
		return (ft_putchar(va_arg(ar, int)));
	else if (chr == 'd' || chr == 'i')
		return (ft_putint(va_arg(ar, int)));
	else if (chr == 'u')
		return (ft_putunsigned(va_arg(ar, unsigned int)));
	else if (chr == 'X')
		return (ft_putuphex(va_arg(ar, unsigned int)));
	else if (chr == 'x')
		return (ft_putdownhex(va_arg(ar, unsigned int)));
	else if (chr == 'p')
		return (ft_putptr(va_arg(ar, unsigned long), 1));
	else if (chr == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		temp;
	int		i;

	va_start(arg, format);
	i = -1;
	len = 0;
	while (format[++i])
	{
		if (format[i] == '%' && ft_check(format[i + 1]))
		{
			temp = ft_format(arg, format[++i]);
		}
		else if (format[i] != '%')
		{
			temp = ft_putchar(format[i]);
		}
		if (temp == -1)
			return (-1);
		len += temp;
		temp = 0;
	}
	va_end(arg);
	return (len);
}
