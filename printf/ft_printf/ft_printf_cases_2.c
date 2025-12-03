/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cases_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:24:43 by pcordero          #+#    #+#             */
/*   Updated: 2025/11/20 13:40:35 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_hex(char const **str, va_list args, unsigned int mayus)
{
	unsigned int	v_int;

	(*str) += 2;
	v_int = va_arg(args, unsigned int);
	if (mayus == 0)
		return (ft_putnbr_base((long)v_int, "0123456789abcdef"));
	return (ft_putnbr_base((long)v_int, "0123456789ABCDEF"));
}
