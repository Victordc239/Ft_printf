/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:04:06 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/04/28 11:45:38 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_s(char *str_s)
{
	int		count_total;
	size_t	j;

	count_total = 0;
	j = 0;
	if (!str_s)
		str_s = "(null)";
	while (str_s[j] != '\0')
	{
		count_total += ft_putchar(str_s[j]);
		j++;
	}
	return (count_total);
}

int	ft_str_ptr(void *str_ptr)
{
	int		count_total;
	size_t	j;

	j = 0;
	count_total = 0;
	if (!str_ptr)
	{
		str_ptr = "(nil)";
		while (((char *)str_ptr)[j] != '\0')
		{
			count_total += ft_putchar(((char *)str_ptr)[j]);
			j++;
		}
	}
	else
	{
		count_total += ft_putchar('0');
		count_total += ft_putchar('x');
		count_total += ft_putnbr_hex((unsigned long)str_ptr);
	}
	return (count_total);
}

int	ft_choose_type(char type, va_list arg)
{
	if (type == '%')
		return (ft_putchar('%'));
	else if (type == 's')
		return (ft_str_s(va_arg(arg, char *)));
	else if (type == 'c')
		return (ft_putchar((char)va_arg(arg, int)));
	else if (type == 'i' || type == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	else if (type == 'u')
		return (ft_putnbr_unsigned(va_arg(arg, unsigned int)));
	else if (type == 'p')
		return (ft_str_ptr(va_arg(arg, void *)));
	else if (type == 'x')
		return (ft_putnbr_hex((unsigned long)va_arg(arg, unsigned int)));
	else if (type == 'X')
		return (ft_putnbr_hex_up((unsigned long)va_arg(arg, unsigned int)));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	size_t	i;
	int		count_total;

	va_start(arg, str);
	count_total = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count_total += ft_choose_type(str[i], arg);
		}
		else
			count_total += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (count_total);
}
/*
int	main(void)
{
	char			*s = "HOLA";
	int			c = 65;
	int			i = 456;
	int			d = 456;
	unsigned int	u = 456;
	char			*p = "HOLA";
	unsigned int	x = 456;
	unsigned int	X = 456;

	printf("COMPARACION PORCENTAJE\n");
	ft_printf("%%\n");
	printf("%%\n");
	printf("---------------------\n");
	
	printf("COMPARACION s\n");
	ft_printf("%s\n", s);
	printf("%s\n", s);
	printf("---------------------\n");

	printf("COMPARACION c\n");
	ft_printf("%c\n", c);
	printf("%c\n", c);
	printf("---------------------\n");

	printf("COMPARACION i\n");
	ft_printf("%i\n", i);
	printf("%i\n", i);
	printf("---------------------\n");

	printf("COMPARACION d\n");
	ft_printf("%d\n", d);
	printf("%d\n", d);
	printf("---------------------\n");

	printf("COMPARACION u\n");
	ft_printf("%u\n", u);
	printf("%u\n", u);
	printf("---------------------\n");

	printf("COMPARACION p\n");
	ft_printf("%p\n", p);
	printf("%p\n", p);
	printf("---------------------\n");

	printf("COMPARACION x\n");
	ft_printf("%x\n", x);
	printf("%x\n", x);
	printf("---------------------\n");

	ft_printf("COMPARACION X\n");
	ft_printf("%X\n", X);
	printf("%X\n", X);
	printf("---------------------\n");

	return (0);
}*/