/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:21:50 by pcordero          #+#    #+#             */
/*   Updated: 2026/02/02 16:21:02 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *init_stack(int argc, char **argv) 
{
	t_list 	*stack;
	int 	*new_content;
	size_t 	idx;

	stack = NULL;
	if (validate_args(argc, argv) != 0)
	{
		idx = 1;
		while (idx < argc)
		{
			new_content = ft_calloc(sizeof(int), 1);
			(*new_content) = ft_atoi(argv[idx]);
			ft_lstadd_front(&stack, ft_lstnew(new_content));
			idx++;
		}
	}
	return (stack);
}


void push_swap(t_list *stack_a) 
{
	int idx = 0;
	while (stack_a != NULL)
	{
		ft_printf("Stack [%d]: %d\n", idx, *((int*)(stack_a->content)));
		idx++;
		stack_a = stack_a->next;
	}
	//print_stacks(stack_a, stack_b);
}