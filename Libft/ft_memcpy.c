/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:11:15 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/14 10:45:50 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t	index;

	if (dest == NULL && src == NULL)
		return (NULL);
	index = 0;
	while (index < count)
	{
		((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dest);
}
