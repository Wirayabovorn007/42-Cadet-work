/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idu_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:45 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/10/14 12:19:40 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	char		res;
	long int	num;

	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
	{
		res = num + '0';
		ft_putchar(res);
	}
}

int	get_nbr_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	handle_int(va_list args)
{
	int	n;

	n = va_arg(args, int);
	ft_putnbr(n);
	return (get_nbr_len(n));
}
