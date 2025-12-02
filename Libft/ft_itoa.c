/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:54:19 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/22 12:31:02 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	num_size;

	num_size = 1;
	if (n / 10 != 0)
		num_size += ft_nbrlen(n / 10);
	return (num_size);
}

static char	*ft_itoa_makestr(int nbr, int negative)
{
	char	*str;
	size_t	str_size;

	str_size = ft_nbrlen(nbr) + negative;
	str = ft_calloc(str_size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (negative == 1)
		str[0] = '-';
	while (nbr / 10 != 0)
	{
		str[str_size - 1] = '0' + (nbr % 10);
		nbr /= 10;
		str_size--;
	}
	str[str_size - 1] = '0' + nbr;
	return (str);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		negative;

	if (nbr == -2147483648)
	{
		str = ft_calloc(12, sizeof(char));
		if (str == NULL)
			return (NULL);
		ft_memcpy(str, "-2147483648", 11);
		return (str);
	}
	negative = 0;
	if (nbr < 0)
	{
		negative = 1;
		nbr *= -1;
	}
	return (ft_itoa_makestr(nbr, negative));
}
