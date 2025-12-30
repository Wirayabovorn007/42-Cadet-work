/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_x_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:42 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/10/14 12:17:01 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long int n)
{
	char	c;
	int		len;

	len = 0;
	if (n >= 16)
		len += print_hex(n / 16);
	if (n % 16 < 10)
		c = (n % 16) + '0';
	else
		c = (n % 16 - 10) + 'a';
	write(1, &c, 1);
	len++;
	return (len);
}

int	print_hex_x(unsigned long int n, const char x)
{
	int		len;
	int		is_upper;
	char	c;

	len = 0;
	is_upper = x == 'X';
	if (n >= 16)
		len += print_hex_x(n / 16, x);
	if (n % 16 < 10)
		c = (n % 16) + '0';
	else
	{
		c = (n % 16 - 10);
		if (is_upper)
			c += 'A';
		else
			c += 'a';
	}
	write(1, &c, 1);
	len++;
	return (len);
}

int	handle_p(va_list args)
{
	int				len;
	unsigned long	n;

	len = 0;
	n = va_arg(args, unsigned long);
	if (!n)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	len += 2;
	len += print_hex(n);
	return (len);
}

int	handle_x(va_list args, const char x)
{
	int				len;
	unsigned int	n;

	len = 0;
	n = va_arg(args, unsigned int);
	if (!n)
	{
		write(1, "0", 1);
		return (1);
	}
	len += print_hex_x(n, x);
	return (len);
}
