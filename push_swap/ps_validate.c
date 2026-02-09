/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:19:43 by pcordero          #+#    #+#             */
/*   Updated: 2026/02/08 13:50:06 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MAX_INT_LEN 10

static int validate_str_length(char* str)
{
	if (ft_isdigit(str[0]) && ft_strlen(str) > MAX_INT_LEN)
		return (0);
	if ((str[0] == '+' || str[0] == '-') && ft_strlen(str) > MAX_INT_LEN + 1)
		return (0);
	
	return (1);
}

static int validate_str_characters(char *str)
{
	int	idx;
	if (!ft_isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return (0);
	idx = 1;
	while (str[idx] != '\0')
	{
		if (!ft_isdigit(str[idx]))
			return (0);
		idx++;
	}
	return (1);
}

static int validate_no_copies(int argc, char **argv)
{
	int idx_1;
	int idx_2;

	idx_1 = 0;
	while (idx_1 < argc)
	{
		idx_2 = idx_1 + 1;
		while (idx_2 < argc)
		{
			if (ft_strncmp(argv[idx_1], argv[idx_2], MAX_INT_LEN) == 0)
				return (0);
			idx_2++;
		}
		idx_1++;
	}
	return (1);
}

int validate_args(int argc, char **argv) 
{
	int valid;
	int idx;

	valid = 1;
	idx = 1;
	while (idx < argc && valid != 0)
		valid = validate_str_length(argv[idx++]);
	idx = 1;
	while (idx < argc && valid != 0)
		valid = validate_str_characters(argv[idx++]);
	if (valid != 0)
		valid = validate_no_copies(argc, argv);
	if (valid == 0)
		ft_printf("Error\n");
	return valid;
}