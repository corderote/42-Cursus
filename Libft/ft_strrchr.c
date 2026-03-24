/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:08:31 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/14 11:07:39 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_strrchr(const char *str, int ch)
{
	size_t	index;

	index = ft_strlen(str);
	while (index >= 0)
	{
		if (str[index] == ch)
			return (&(str[index]));
		index--;
	}
	return (NULL);
}
*/

char	*ft_strrchr(const char *str, int ch)
{
	size_t	index;

	index = ft_strlen(str);
	while (index > 0 && str[index] != (unsigned char)ch)
		index--;
	if ((str[index]) == (unsigned char)ch)
		return ((char *)&(str[index]));
	return (NULL);
}
