/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:15:05 by pcordero          #+#    #+#             */
/*   Updated: 2026/02/02 17:27:13 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **stack)
{
	t_list *aux;

	if ((*stack)->next != NULL)
	{
		aux = (*stack)->next;
		(*stack)->next = aux->next;
		aux->next = (*stack);
		(*stack) = aux;
	}
}

void push(t_list stack_a, t_list stack_b)
{
	
}

void rotate(t_list stack)
{
	
}