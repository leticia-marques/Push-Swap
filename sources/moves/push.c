/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:57:48 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 16:59:35 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	empty_after_push_to_empty(t_stack *src, t_stack *dst)
{
	dst->top = src->top;
	dst->begin = src->begin;
	src->top = NULL;
	src->begin = NULL;
}

static void	empty_after_push_to_not_empty(t_stack *src, t_stack *dst)
{
	dst->top->next = src->top;
	src->top->prev = dst->top;
	dst->top = src->top;
	src->top = NULL;
	src->begin = NULL;
}

static void	not_empty_after_push_to_empty(t_stack *src, t_stack *dst)
{
	dst->top = src->top;
	dst->begin = src->top;
	src->top = src->top->prev;
	dst->begin->prev = NULL;
	src->top->next = NULL;
}

static void	not_empty_after_push_to_not_empty(t_stack *src, t_stack *dst)
{
	dst->top->next = src->top;
	src->top = src->top->prev;
	src->top->next = NULL;
	dst->top->next->prev = dst->top;
	dst->top = dst->top->next;
}

void	push(t_stack *src, t_stack *dst)
{
	if (!src || !dst || src->size == 0)
		return ;
	if (dst->name == 'a')
		write(1, "pa\n", 3);
	else if (dst->name == 'b')
		write(1, "pb\n", 3);
	if (src->size == 1 && dst->size == 0)
		empty_after_push_to_empty(src, dst);
	else if (src->size == 1 && dst->size > 0)
		empty_after_push_to_not_empty(src, dst);
	else if (src->size > 1 && dst->size == 0)
		not_empty_after_push_to_empty(src, dst);
	else if (src->size > 1 && dst->size > 0)
		not_empty_after_push_to_not_empty(src, dst);
	src->size--;
	dst->size++;
}
