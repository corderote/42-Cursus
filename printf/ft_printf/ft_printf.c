/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:10:40 by pcordero          #+#    #+#             */
/*   Updated: 2025/12/03 11:49:50 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_printf_printarg(char const **str, va_list args)
{
	if ((*((*str) + 1)) == 'c')
		return (ft_printf_char(str, args));
	if ((*((*str) + 1)) == 's')
		return (ft_printf_str(str, args));
	if ((*((*str) + 1)) == 'p')
		return (ft_printf_ptr(str, args));
	if ((*((*str) + 1)) == 'd' || (*((*str) + 1)) == 'i')
		return (ft_printf_int(str, args));
	if ((*((*str) + 1)) == 'u')
		return (ft_printf_uint(str, args));
	if ((*((*str) + 1)) == 'x')
		return (ft_printf_hex(str, args, 0));
	if ((*((*str) + 1)) == 'X')
		return (ft_printf_hex(str, args, 1));
	if ((*((*str) + 1)) == '%')
	{
		(*(str)) += 2;
		return (write(1, "%", 1));
	}
	(*(str))++;
	return (write(1, "%", 1));
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	size_t	str_size;

	if (str == NULL)
		return (-1);
	str_size = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str != '%')
		{
			write(1, str, 1);
			str++;
			str_size++;
		}
		else
			str_size += ft_printf_printarg(&str, args);
	}
	va_end(args);
	return (str_size);
}
