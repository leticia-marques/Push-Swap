/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_top_to_bottom.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:41:16 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 17:56:07 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	rotate_top_to_bottom_act(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	first = stack->top;
	last = stack->begin;
	stack->top = first->prev;
	stack->begin = first;
	stack->begin->next = last;
	stack->begin->next->prev = first;
	stack->top->next = NULL;
	stack->begin->prev = NULL;
}

void	rotate_top_to_bottom(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	if (stack->size == 2)
		swap(stack);
	else
		rotate_top_to_bottom_act(stack);
}
