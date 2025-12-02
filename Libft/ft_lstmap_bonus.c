/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:58:20 by pcordero          #+#    #+#             */
/*   Updated: 2025/10/15 18:17:39 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_dest;
	t_list	*lst_aux;
	void	*new_content;

	lst_dest = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_content = f(lst->content);
		lst_aux = ft_lstnew(new_content);
		if (lst_aux == NULL)
		{
			ft_lstclear(&lst_dest, del);
			del(new_content);
			return (NULL);
		}
		else
			ft_lstadd_back(&lst_dest, lst_aux);
		lst = lst->next;
	}
	return (lst_dest);
}
