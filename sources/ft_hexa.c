/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:29:11 by alramire          #+#    #+#             */
/*   Updated: 2024/05/24 15:39:03 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_hexa_helper(unsigned int n, char format)
{
	const char	*hex_small = "0123456789abcdef";
	const char	*hex_big = "0123456789ABCDEF";
	int			len;

	len = 0;
	if (n > 0)
	{
		len += ft_hexa_helper(n / 16, format);
		if (format == 'x')
			len += ft_putchar(hex_small[n % 16]);
		if (format == 'X')
			len += ft_putchar(hex_big[n % 16]);
	}
	return (len);
}

int	ft_hexa(unsigned int n, char format)
{
	if (n == 0)
		return (ft_putchar('0'));
	else
		return (ft_hexa_helper(n, format));
}
