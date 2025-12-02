/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:08:27 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/14 11:06:44 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_strchr(const char *str, int ch)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == ch)
			return (&(str[index]));
		index++;
	}
	if (ch == '\0')
		return (&(str[index]));
	return (NULL);
}
*/
// NOTE: Casting to unsigned char does the same as doing the module (ch % 128)
// 		 making sure that we are working between the limits of the ASCII table.

char	*ft_strchr(const char *str, int ch)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0' && str[index] != (unsigned char)ch)
		index++;
	if (str[index] == (unsigned char)ch)
		return ((char *)&(str[index]));
	return (NULL);
}
