/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:08:50 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/09 14:43:43 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	size_t	index;

	index = 0;
	while (index < count && ((unsigned char *)ptr)[index] != (unsigned char)ch)
		index++;
	if (index < count)
		return (&(((unsigned char *)ptr)[index]));
	return (NULL);
}
