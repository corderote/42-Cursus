/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:54:46 by pcordero          #+#    #+#             */
/*   Updated: 2026/01/31 18:04:28 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	t_list *stack;

	stack = init_stack(argc, argv);
	if (stack != NULL)
		push_swap(stack);
	ft_lstclear(&stack, free);
	return (0);
}