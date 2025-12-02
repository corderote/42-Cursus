/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:57:40 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/08 12:24:30 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *src, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	index;
	size_t			s_len;

	if (src == NULL || f == NULL)
		return (NULL);
	s_len = ft_strlen(src);
	dest = ft_calloc(s_len + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = f(index, src[index]);
		index++;
	}
	return (dest);
}
