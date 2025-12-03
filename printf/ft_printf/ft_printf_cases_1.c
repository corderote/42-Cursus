/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cases_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:16:50 by pcordero          #+#    #+#             */
/*   Updated: 2025/11/20 13:24:23 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_char(char const **str, va_list args)
{
	unsigned char	v_char;

	(*str) += 2;
	v_char = (unsigned char)va_arg(args, int);
	return (write(1, &v_char, 1));
}

size_t	ft_printf_str(char const **str, va_list args)
{
	char	*v_str;

	v_str = va_arg(args, char *);
	(*str) += 2;
	if (v_str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, v_str, ft_strlen(v_str)));
}

size_t	ft_printf_ptr(char const **str, va_list args)
{
	void	*v_ptr;

	(*str) += 2;
	v_ptr = va_arg(args, void *);
	if (v_ptr == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_putnbr_base((unsigned long)v_ptr, "0123456789abcdef") + 2);
}

size_t	ft_printf_int(char const **str, va_list args)
{
	int	v_int;
	int	negative;

	(*str) += 2;
	negative = 0;
	v_int = va_arg(args, int);
	if (v_int == -2147483648)
		return (write(1, "-2147483648", 11));
	if (v_int < 0)
	{
		negative = write(1, "-", 1);
		v_int = -v_int;
	}
	return (ft_putnbr_base((long)v_int, "0123456789") + negative);
}

size_t	ft_printf_uint(char const **str, va_list args)
{
	unsigned int	v_uint;

	(*str) += 2;
	v_uint = va_arg(args, unsigned int);
	return (ft_putnbr_base((long)v_uint, "0123456789"));
}
