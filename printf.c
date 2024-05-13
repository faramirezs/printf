/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:20:27 by alramire          #+#    #+#             */
/*   Updated: 2024/05/13 17:30:35 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
	{
		write(fd, &c, 1);
	}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putstr_fd("8", fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_hexa_helper(unsigned long n, char format)
{
	char	*hex;
	int		i;

	i = 0;
	if (format == "x")
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n > 0)
	{
		ft_hexa(n / 16, format);
		ft_putchar_fd(hex[n % 16], 1);
	}
}

void	ft_hexa(unsigned long n, char format)
{
	char	*hex;
	int		i;

	i = 0;
	if (format == "x")
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n > 0)
	{
		ft_hexa(n / 16, format);
		ft_putchar_fd(hex[n % 16], 1);
	}
}
void	ft_pointer_helper(unsigned long n)
{
	char	*hex;
	int		i;

	i = 0;
	hex = "0123456789abcdef";
	if (n > 0)
	{
		ft_pointer_helper(n / 16);
		ft_putchar_fd(hex[n % 16], 1);
	}
}

void	ft_pointer(unsigned long n)
{
	ft_putstr_fd("0x", 1);
	ft_pointer_helper(n);
}

void	ft_write_options(va_list val, char c)
{
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(val, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(val, char *), 1);
	else if (c == 'c')
		ft_putchar_fd(va_arg(val, char), 1);
	else if (c == 'x' || c == 'X')
		ft_hexa((long)va_arg(val, char *), c);
	else if (c == 'p')
		ft_pointer((long)va_arg(val, char *));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	val;

	i = 0;
	va_start(val, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_write_options(val, format[i + 1]);
		}
		else
			ft_putchar_fd((format[i]), 1);
		i++;
	}
	va_end(val);
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
	ft_printf("Areté = %p. Areté = %p. Areté = %p.\n\n\n", s1, s2, s3);
	printf("Areté = %p. Areté = %p. Areté = %p.\n\n\n", s1, s2, s3);




/* 	long	a;
	long	b;
	long	c;

	a = 123;
	b = 456;
	c = 0;
	ft_printf("Test 1: just zero.\n");
	ft_printf("Areté. %x Areté. %x Areté. %x\n\n\n", a, b, c); */

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
