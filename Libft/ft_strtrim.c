/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:22:49 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/15 10:07:03 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	char			*trimstr;
	size_t			index;
	unsigned int	trim_start;
	unsigned int	trim_end;
	size_t			trim_len;

	index = 0;
	while (ft_strchr(set, str[index]) != NULL)
		index++;
	trim_start = index;
	index = ft_strlen(str);
	while (ft_strchr(set, str[index]) != NULL)
		index--;
	trim_end = index;
	trim_len = trim_end - trim_start;
	trimstr = ft_substr(str, trim_start, trim_len + 1);
	return (trimstr);
}
