/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:20:27 by alramire          #+#    #+#             */
/*   Updated: 2024/05/13 09:20:00 by alramire         ###   ########.fr       */
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

void	ft_hexa(int n)
{
	char	*hex;
	int		i;

	i = 0;
	hex = "0123456789ABCDEF";
	if (n > 0)
	{
		ft_hexa(n / 16);
		ft_putchar_fd(hex[n % 16], 1);
	}
}

void	ft_write_options(va_list val, char c)
{
	if (c == 'd')
		ft_putnbr_fd(va_arg(val, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(val, char *), 1);
	else if (c == 'c')
		ft_putchar_fd(va_arg(val, char), 1);
	else if (c == 'p')
		ft_putstr_fd(va_arg(val, char *), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(val, char *), 1);
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
	int	n;

	n = 287;
	ft_hexa(n);
	return(0);





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
