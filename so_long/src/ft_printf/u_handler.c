/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:18:11 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/10/14 12:19:35 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_unsigned_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_put_unsigned_nbr(unsigned int n)
{
	char			res;
	unsigned long	num;

	num = n;
	if (num > 9)
	{
		ft_put_unsigned_nbr((num / 10));
		ft_put_unsigned_nbr((num % 10));
	}
	else
	{
		res = num + '0';
		ft_putchar(res);
	}
}

int	handle_unsigned_int(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ft_put_unsigned_nbr(n);
	return (get_unsigned_len(n));
}
