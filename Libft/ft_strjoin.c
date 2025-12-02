/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:13:57 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/14 10:05:37 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fullstr;

	fullstr = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (fullstr == NULL)
		return (NULL);
	ft_strlcat(fullstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(fullstr, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (fullstr);
}
