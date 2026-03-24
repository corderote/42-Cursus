/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:11:32 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/07 13:32:08 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	if (dest > src)
	{
		while (count > 0)
		{
			((unsigned char *)dest)[count - 1]
				= ((unsigned char *)src)[count - 1];
			count--;
		}
	}
	else
		ft_memcpy(dest, src, count);
	return (dest);
}
/*	ALT VERSION WITH MALLOC:
void	*ft_memmove(void *dest, const void *src, size_t count)
{
	void	*aux;

	aux = malloc(sizeof(unsigned char) * count);
	ft_memcpy(aux, src, count);
	ft_memcpy(dest, aux, count);
	free(aux);
	return (dest);
}
*/