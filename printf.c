/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:20:27 by alramire          #+#    #+#             */
/*   Updated: 2024/05/20 16:21:26 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	if(!s)
		return (ft_putstr("(null)"));
	return(write(1,s,ft_strlen(s)));
}

int	ft_putchar(char c)
{
	return(write(1, &c, 1));
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
	return(len);
}

int	ft_hexa_helper(unsigned long n, char format)
{
	char	*hex;
	int		i;
	int		len;

	i = 0;
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
	return(len);
}

int	ft_hexa(unsigned long n, char format)
{
	if (n == 0)
		return(ft_putchar('0'));
	else
		return(ft_hexa_helper(n, format));
}
int	ft_pointer_helper(unsigned long n)
{
	char	*hex;
	int		i;
	int		len;

	i = 0;
	hex = "0123456789abcdef";
	len = 0;
	if (n > 0)
	{
		len += ft_pointer_helper(n / 16);
		len += ft_putchar(hex[n % 16]);
	}
	return(len);
}

int	ft_pointer(unsigned long n)
{
	return(ft_putstr("0x") + ft_pointer_helper(n));
}

int	ft_write_options(va_list val, char c)
{
	if (c == 'd' || c == 'i')
		return(ft_putnbr(va_arg(val, int)));
	else if (c == 's')
		return(ft_putstr(va_arg(val, char *)));
	else if (c == 'c')
		return(ft_putchar(va_arg(val, int)));
	else if (c == 'x' || c == 'X')
		return(ft_hexa((long)va_arg(val, char *), c));
	else if (c == 'p')
		return(ft_pointer((long)va_arg(val, char *)));
/* 	else if (c == 'u')
		return(ft_unsigned_int(va_arg(val, unsigned int))); */
	else if (c == '%')
		return(ft_putchar('%'));
	return(0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	val;
	int		len;

	i = 0;
	len = 0;
	va_start(val, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_write_options(val, format[i + 1]);
		}
		else
			len += ft_putchar((format[i]));
		i++;
	}
	va_end(val);
	return(len);
}

int	main(void)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = "Areté";
	s2 = "Areté";
	s3 = "Areté";

	ft_printf("Test 2: just POINTERS\n");
	ft_printf("Caracteres impresos: %d\n",ft_printf("Test 2: just POINTERS\n"));
	ft_printf("Areté = %p. Areté = %p. Areté = %%.\n\n\n", s1, s2, s3);
	ft_printf("Caracteres impresos: %d\n",ft_printf("Areté = %p. Areté = %p. Areté = %%.\n\n\n", s1, s2, s3));
	printf("printf: Areté = %p. Areté = %p. Areté = %p.\n\n\n", s1, s2, s3);
	printf("printf caracteres impresos: %d\n",ft_printf("Areté = %p. Areté = %p. Areté = %%.\n\n\n", s1, s2, s3));

	long	a;
	long	b;
	long	c;

	a = 123;
	b = 456;
	c = 0;
	ft_printf("Test 1: just zero.\n");
	ft_printf("Caracteres impresos: %d\n",ft_printf("Test 2: just POINTERS\n"));
	printf("printf caracteres impresos: %d\n",ft_printf("Test 2: just POINTERS\n"));
	ft_printf("Areté. %x Areté. %x Areté. %x\n\n\n", a, b, c);
	ft_printf("Caracteres impresos: %d\n",ft_printf("Areté. %x Areté. %x Areté. %x\n\n\n", a, b, c));
	printf("printf: Areté. %x Areté. %x Areté. %x\n\n\n", a, b, c);
	printf("printf caracteres impresos: %d\n",ft_printf("Areté. %x Areté. %x Areté. %x\n\n\n", a, b, c));


/* 	ft_printf("Test 2: All\n");
	ft_printf("Areté = %X. Areté = %d. Areté = %d.\n\n\n", a, b, c); */





/* 	long		n;
	char	*p;

	n = 0;
	p = &n;
	ft_printf("Test 1: n = 0\n");
	ft_hexa(n, "x");
	ft_printf("\n\n\n");

	ft_printf("Test 2: n = 287\n");
	n = 287;
	ft_hexa(n, "x");
	ft_printf("\n\n\n");

	ft_printf("Test 3: n = 9001\n");
	n = 9001;
	ft_hexa(n, "x");
	ft_printf("\n\n\n");

	ft_printf("Test 4: n = 99\n");
	n = 99;
	ft_hexa(n, "x");
	ft_printf("\n\n\n");

	ft_printf("Test 5: n = long\n");
	ft_hexa((long)p, "x");
		ft_printf("\n\n\n");

	ft_printf("Test 6: n = pointer\n");
	printf("Pointer address: %p Integer address: %ld\n", p, (long)p);

	return(0); */





	/* int		a;
	int		b;
	int		c;
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = "Areté";
	s2 = "Areté";
	s3 = "Areté";
	a = 123;
	b = 456;
	c = 0;
	ft_printf("Test 1: just text.\n");
	ft_printf("Areté. Areté. Areté.\n\n\n");
	ft_printf("Test 2: just strings\n");
	ft_printf("Areté = %s. Areté = %s. Areté = %s.\n\n\n", s1, s2, s3);
	ft_printf("Test 3: just integers\n");
	ft_printf("Areté = %d. Areté = %d. Areté = %d.\n\n\n", a, b, c); */
}
