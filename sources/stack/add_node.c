/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:32:39 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/09 18:37:45 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	add_node(t_stack *stack, int value)
{
	t_node	*node;

	if (!stack)
		return ;
	node = node_create(value);
	if (!node)
		return ;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->begin = node;
	}
	else
	{
		stack->top->next = node;
		node->prev = stack->top;
		stack->top = node;
	}
	stack->size++;
}
