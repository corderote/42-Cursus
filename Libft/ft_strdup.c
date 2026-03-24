/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:22:47 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/02 14:47:28 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*new_src;

	new_src = ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (new_src == NULL)
		return (NULL);
	ft_strlcpy(new_src, src, ft_strlen(src) + 1);
	return (new_src);
}
