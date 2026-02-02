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

int validate_args(int argc, char **argv) 
{
	int valid;
	int idx;

	valid = 0;
	for (int i=1; i<argc && valid != -1; i++)
	{
		// Valid first char [number, + or -].
		if (!ft_isdigit(argv[i][0]) && argv[i][0] != '+' && argv[i][0] != '-')
			valid = -1;
		// Valid str length.
		if ((argv[i][0] != '+' || argv[i][0] != '-') && ft_strlen(argv[i]) > 10)
			valid = -1;
		if ((argv[i][0] == '+' || argv[i][0] == '-') && ft_strlen(argv[i]) > 11)
			valid = -1;
		// Valid all str chars.
		idx = 1;
		while (argv[i][idx] != '\0' && valid != -1)
		{
			if (!ft_isdigit(argv[i][idx]))
				valid = -1;
			idx++;
		}
		// No copies from the stack.  
		for (int j = i - 1; j > 1 && valid != -1; j--)
		{
			if (ft_strncmp(argv[i], argv[j], 11) == 0)
				valid = -1;
		}
	}
	
	if (valid == -1)
		ft_printf("Error\n");
	return valid;
}

t_list *init_stack(int argc, char **argv) 
{
	t_list 	*stack;
	int 	*new_content;
	size_t 	idx;

	stack = NULL;
	if (validate_args(argc, argv) != -1)
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