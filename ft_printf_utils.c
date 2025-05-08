/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:04:23 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/04/25 10:22:51 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	count_total;

	count_total = 0;
	write(1, &c, 1);
	count_total++;
	return (count_total);
}

int	ft_putnbr_hex_up(unsigned long n)
{
	int	count_total;

	count_total = 0;
	if (n >= 16)
		count_total += ft_putnbr_hex_up(n / 16);
	ft_putchar("0123456789ABCDEF"[n % 16]);
	count_total++;
	return (count_total);
}

int	ft_putnbr_hex(unsigned long n)
{
	int	count_total;

	count_total = 0;
	if (n >= 16)
		count_total += ft_putnbr_hex(n / 16);
	ft_putchar("0123456789abcdef"[n % 16]);
	count_total++;
	return (count_total);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count_total;

	count_total = 0;
	if (n >= 10)
	{
		count_total += ft_putnbr_unsigned(n / 10);
		count_total += ft_putnbr_unsigned(n % 10);
	}
	else
	{
		count_total++;
		ft_putchar(n + '0');
	}
	return (count_total);
}

int	ft_putnbr(int n)
{
	int	count_total;

	count_total = 0;
	if (n == -2147483648)
	{
		count_total += ft_putchar('-');
		count_total += ft_putchar('2');
		count_total += ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		count_total += ft_putchar('-');
		count_total += ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		count_total += ft_putnbr(n / 10);
		count_total += ft_putnbr(n % 10);
	}
	else
		count_total += ft_putchar(n + '0');
	return (count_total);
}
