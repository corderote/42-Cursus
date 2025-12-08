/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:56:09 by pcordero          #+#    #+#             */
/*   Updated: 2025/12/08 11:25:49 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	lenght;

	lenght = 0;
	while (str[lenght] != '\0')
		lenght++;
	return (lenght);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	index;

	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (ft_strlen(src) + size);
	index = 0;
	while (src[index] != '\0' && dest_len + index < size - 1)
	{
		dest[dest_len + index] = src[index];
		index++;
	}
	dest[dest_len + index] = '\0';
	return (ft_strlen(src) + dest_len);
}

void	*ft_memset(void *dest, int ch, size_t count)
{
	size_t	index;

	index = 0;
	while (index < count)
	{
		((unsigned char *)dest)[index] = ch;
		index++;
	}
	return (dest);
}

void	*ft_calloc(size_t num_mem_blocks, size_t size_mem_blocks)
{
	void	*ptr;
	size_t	mem_to_alloc;

	if (num_mem_blocks == 0 || size_mem_blocks == 0)
		return (malloc(0));
	if ((num_mem_blocks == __SIZE_MAX__ && size_mem_blocks > 1)
		|| (size_mem_blocks == __SIZE_MAX__ && num_mem_blocks > 1))
		return (NULL);
	mem_to_alloc = size_mem_blocks;
	while (num_mem_blocks > 1)
	{
		if (mem_to_alloc > mem_to_alloc + size_mem_blocks)
			return (NULL);
		mem_to_alloc += size_mem_blocks;
		num_mem_blocks--;
	}
	ptr = malloc(mem_to_alloc);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, '\0', mem_to_alloc);
	return (ptr);
}
