/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:18:09 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/21 10:25:02 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_split_free(char **lst, size_t list_size)
{
	size_t	index;

	index = 0;
	while (index < list_size)
	{
		free(lst[index]);
		index++;
	}
	free(lst);
}

static size_t	ft_split_count(char const *str, char ch)
{
	size_t	split_count;

	split_count = 0;
	while (*str == ch)
		str++;
	while (str != NULL && *str != '\0')
	{
		split_count++;
		str = ft_strchr(str, ch);
		while (str != NULL && *str == ch)
			str++;
	}
	return (split_count);
}

static char	**ft_split_add(char **lst, const char *str, char ch, size_t l_size)
{
	size_t	index;
	size_t	w_start;
	size_t	w_len;

	index = 0;
	w_start = 0;
	while (index < l_size)
	{
		while (str[w_start] == ch)
			w_start++;
		w_len = 0;
		while (str[w_start + w_len] != ch && str[w_start + w_len] != '\0')
			w_len++;
		lst[index] = ft_substr(str, w_start, w_len);
		if (lst[index] == NULL)
		{
			ft_split_free(lst, index);
			return (NULL);
		}
		w_start += w_len;
		index++;
	}
	lst[index] = NULL;
	return (lst);
}

static char	**ft_split_endofstrchr(char **lst, const char *str)
{
	if (lst != NULL)
	{
		if (str[0] != '\0')
		{
			lst[0] = ft_calloc(1, ft_strlen(str) + 1);
			if (lst[0] == NULL)
			{
				ft_split_free(lst, 0);
				return (NULL);
			}
			if (lst[0] != NULL)
				ft_memcpy(lst[0], str, ft_strlen(str) + 1);
		}
		else
			lst[0] = NULL;
		lst[1] = NULL;
		return (lst);
	}
	return (NULL);
}

char	**ft_split(char const *str, char ch)
{
	size_t	s_count;
	char	**s_list;

	if (str == NULL)
		return (NULL);
	if ((unsigned char)ch == '\0')
	{
		s_list = ft_calloc(2, sizeof(char *));
		if (s_list == NULL)
			return (NULL);
		return (ft_split_endofstrchr(s_list, str));
	}
	s_count = ft_split_count(str, (unsigned char)ch);
	s_list = ft_calloc(s_count + 1, sizeof(char *));
	if (s_list != NULL)
		s_list = ft_split_add(s_list, str, (unsigned char)ch, s_count);
	return (s_list);
}
