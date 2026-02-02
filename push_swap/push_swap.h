/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:23:15 by pcordero          #+#    #+#             */
/*   Updated: 2026/02/02 17:30:11 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "printf/ft_printf/ft_printf.h"


t_list *init_stack(int argc, char **argv);
void push_swap(t_list *stack);

// Push Swap Commands.
void push(t_list stack_a, t_list stack_b);
void swap(t_list stack);
void rotate(t_list stack);

