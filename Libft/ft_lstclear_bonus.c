/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:47:09 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/15 16:42:18 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_aux;

	while (*lst != NULL && del != NULL)
	{
		lst_aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst_aux;
	}
}
