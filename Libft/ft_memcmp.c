/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:08:55 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/14 11:09:31 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *lhs, const void *rhs, size_t count)
{
	size_t	index;

	index = 0;
	while (index < count
		&& ((unsigned char *)lhs)[index] == ((unsigned char *)rhs)[index])
		index++;
	if (index < count)
		return (((unsigned char *)lhs)[index] - ((unsigned char *)rhs)[index]);
	return (0);
}
