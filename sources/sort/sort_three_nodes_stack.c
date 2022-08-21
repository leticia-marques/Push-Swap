/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nodes_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:42:52 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 16:37:57 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_three_nodes_stack(t_stack *stack)
{
	int	begin;
	int	middle;
	int	top;

	begin = stack->begin->value;
	middle = stack->begin->next->value;
	top = stack->top->value;
	if (middle == find_smallest(stack) && begin == find_highest(stack))
		single_swap(stack);
	else if (top == find_highest(stack) && begin == find_smallest(stack))
	{
		single_swap(stack);
		single_rotate_bottom_to_top(stack);
	}
	else if (top == find_highest(stack) && middle == find_smallest(stack))
		single_rotate_top_to_bottom(stack);
	else if (top == find_smallest(stack) && middle == find_highest(stack))
	{
		single_swap(stack);
		single_rotate_top_to_bottom(stack);
	}
	else if (begin == find_smallest(stack) && middle == find_highest(stack))
		single_rotate_bottom_to_top(stack);
}
