/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:03:55 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/04/25 10:22:33 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr(int n);
int	ft_putnbr_hex(unsigned long n);
int	ft_putchar(char c);
int	ft_putnbr_hex_up(unsigned long n);
int	ft_str_ptr(void *str_ptr);
int	ft_str_s(char *str_s);
int	ft_choose_type(char format, va_list arg);

#endif