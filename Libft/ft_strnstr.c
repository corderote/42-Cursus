/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:08:58 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/14 13:14:03 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	index = 0;
	while (haystack[index] != '\0' && index <= len - n_len && n_len <= len)
	{
		if (ft_strncmp(&(haystack[index]), needle, n_len) == 0)
			return ((char *)(&(haystack[index])));
		index++;
	}
	return (NULL);
}
