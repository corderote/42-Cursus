/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:09:06 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/09 15:53:47 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int	ft_strncmp(const char *lhs, const char *rhs, size_t count)
{
	size_t	index;

	index = 0;
	while (lhs[index] != '\0' && rhs[index] != '\0' && index < count)
	{
		if (lhs[index] != rhs[index])
			return (lhs[index] - rhs[index]);
		index++;
	}
	if (index == count)
		return (0);
	return (lhs[index] - rhs[index]);
}
*/

int	ft_strncmp(const char *lhs, const char *rhs, size_t count)
{
	size_t	index;

	index = 0;
	while (index < count && lhs[index] == rhs[index]
		&& lhs[index] != '\0' && lhs[index] != '\0')
		index++;
	if (index < count)
		return ((unsigned char)(lhs[index]) - (unsigned char)(rhs[index]));
	return (0);
}
