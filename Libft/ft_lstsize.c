/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:22:55 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/09 11:19:51 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lst_size;

	if (lst == NULL)
		return (0);
	lst_size = 0;
	while (lst != NULL)
	{
		lst_size++;
		lst = lst->next;
	}
	return (lst_size);
}
