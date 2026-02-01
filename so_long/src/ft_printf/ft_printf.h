/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:28 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/10/14 12:12:54 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h> 

int		ft_printf(const char *format, ...);
void	ft_putnbr(int n);
int		ft_putchar(char c);
int		get_nbr_len(int n);
int		ft_putstr(char *str);
int		handle_x(va_list args, const char x);
int		handle_p(va_list args);
int		handle_int(va_list args);
int		handle_unsigned_int(va_list args);
int		handle_i(va_list args);

#endif