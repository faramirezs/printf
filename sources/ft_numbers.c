/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:21:07 by alramire          #+#    #+#             */
/*   Updated: 2024/05/22 12:48:52 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_unsigned_int(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_unsigned_int(n / 10);
	len += ft_putchar(n % 10 + '0');
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putnbr(n / 10);
		len += ft_putstr("8");
	}
	else if (n < 0)
	{
		len += ft_putchar('-');
		len += ft_putnbr(-n);
	}
	else
	{
		if (n > 9)
			len += ft_putnbr(n / 10);
		len += ft_putchar(n % 10 + '0');
	}
	return (len);
}

int	ft_hexa_helper(unsigned long n, char format)
{
	char	*hex;
	int		len;

	len = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n > 0)
	{
		ft_hexa_helper(n / 16, format);
		len += ft_putchar(hex[n % 16]);
	}
	return (len);
}

int	ft_hexa(unsigned long n, char format)
{
	if (n == 0)
		return (ft_putchar('0'));
	else
		return (ft_hexa_helper(n, format));
}

int	ft_pointer_helper(unsigned long n)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = 0;
	if (n > 0)
	{
		len += ft_pointer_helper(n / 16);
		len += ft_putchar(hex[n % 16]);
	}
	return (len);
}

int	ft_pointer(unsigned long n)
{
	return (ft_putstr("0x") + ft_pointer_helper(n));
}
