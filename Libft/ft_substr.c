/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:00:29 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/14 13:52:47 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	index;

	if (str == NULL)
		return (NULL);
	if (start > ft_strlen(str))
	{
		start = 0;
		len = 0;
	}
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	substr = ft_calloc(len + 1, sizeof(char));
	if (substr == NULL)
		return (NULL);
	index = 0;
	while (str[start + index] != '\0' && index < len)
	{
		substr[index] = str[start + index];
		index++;
	}
	return (substr);
}
