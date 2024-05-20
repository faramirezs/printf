/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:58:49 by alramire          #+#    #+#             */
/*   Updated: 2024/05/20 17:38:18 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:58:52 by alramire          #+#    #+#             */
/*   Updated: 2024/05/08 10:10:45 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

/* Prototypes */
int		ft_unsigned_int(unsigned int n);
int		ft_putnbr(int n);
int		ft_hexa_helper(unsigned long n, char format);
int		ft_hexa(unsigned long n, char format);
int		ft_pointer_helper(unsigned long n);
int		ft_pointer(unsigned long n);
size_t	ft_strlen(char const *s);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int	ft_write_options(va_list val, char c);
int	ft_printf(const char *format, ...);

#endif
