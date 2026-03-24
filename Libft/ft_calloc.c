/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:22:21 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/15 11:14:14 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
