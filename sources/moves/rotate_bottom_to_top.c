/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bottom_to_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:50:48 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 17:55:05 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	rotate_bottom_to_top_act(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	first = stack->top;
	last = stack->begin;
	stack->begin = last->next;
	stack->begin->prev = NULL;
	stack->top = last;
	stack->top->prev = first;
	stack->top->prev->next = last;
	stack->top->next = NULL;
}

void	rotate_bottom_to_top(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	if (stack->size == 2)
		swap(stack);
	else
		rotate_bottom_to_top_act(stack);
}
