/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_nodes_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:49:21 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 21:00:20 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(t_stack *stack, int value)
{
	t_node	*aux;
	int		count;

	count = 0;
	if (stack)
	{
		aux = stack->top;
		while (aux)
		{
			if (aux->value == value)
				return (count);
			aux = aux->prev;
			count++;
		}
	}
	return (count);
}

void	sort_four_nodes_stack(t_stacks *stacks)
{
	int	smallest;

	if (stacks)
	{
		smallest = find_smallest(stacks->stack_a);
		if (get_index(stacks->stack_a, smallest) < stacks->stack_a->size / 2)
		{
			if (stacks->stack_a->top->value != smallest)
				single_swap(stacks->stack_a);
		}
		else
		{
			if (stacks->stack_a->begin->value != smallest)
				single_rotate_bottom_to_top(stacks->stack_a);
			single_rotate_bottom_to_top(stacks->stack_a);
		}
		push(stacks->stack_a, stacks->stack_b);
		sort_three_nodes_stack(stacks->stack_a);
		push(stacks->stack_b, stacks->stack_a);
	}
}
