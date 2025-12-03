/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:42:39 by pcordero          #+#    #+#             */
/*   Updated: 2025/12/03 20:18:26 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	lenght;

	lenght = 0;
	while (str[lenght] != '\0')
		lenght++;
	return (lenght);
}

int	ft_putnbr_base(long number, const char *base)
{
	const size_t	b_size = ft_strlen(base);
	size_t			n_size;

	n_size = 1;
	if (number / b_size != 0)
		n_size += ft_putnbr_base(number / b_size, base);
	write(1, &(base[number % b_size]), 1);
	return (n_size);
}
