/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:09:02 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/22 12:30:08 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int ch)
{
	return (ch == ' ' || ch == '\f' || ch == '\n'
		|| ch == '\r' || ch == '\t' || ch == '\v');
}

static int	ft_atoi_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	res = 1;
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}

static int	ft_atoi_numfromstr(const char *str, int idx_start, int idx_end)
{
	int	number;
	int	digit;

	number = 0;
	digit = 0;
	while (idx_end - digit > idx_start)
	{
		number += ((str[idx_end - digit - 1] - '0') * ft_atoi_power(10, digit));
		digit++;
	}
	return (number);
}

int	ft_atoi(const char *str)
{
	int	number;
	int	index_start;
	int	index_end;
	int	is_negative;

	index_start = 0;
	is_negative = 1;
	while (ft_isspace(str[index_start]))
		index_start++;
	if (str[index_start] == '+' || str[index_start] == '-')
	{
		if (str[index_start] == '-')
			is_negative = -1;
		index_start++;
	}
	index_end = index_start;
	while (ft_isdigit(str[index_end]))
		index_end++;
	number = ft_atoi_numfromstr(str, index_start, index_end);
	return (number * is_negative);
}
