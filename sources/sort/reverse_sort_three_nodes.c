/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_sort_three_nodes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:39:16 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 17:39:46 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_two_at_top_b(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->stack_b->top->value < stacks->stack_b->top->prev->value)
			single_swap(stacks->stack_b);
		push(stacks->stack_b, stacks->stack_a);
		push(stacks->stack_b, stacks->stack_a);
	}
}

static void	bigger_first(t_stacks *stacks, t_sort *sort)
{
	if (sort->second < sort->third)
	{
		push(stacks->stack_b, stacks->stack_a);
		sort->index--;
		single_swap(stacks->stack_b);
	}
}

static void	average_first(t_stacks *stacks, t_sort *sort)
{
	if (sort->first < sort->second \
		&& sort->second > sort->third \
		&& sort->third < sort->first)
	{
		single_swap(stacks->stack_b);
	}
	else if (sort->first > sort->second \
		&& sort->second < sort->third \
		&& sort->third > sort->first)
	{
		single_rotate_top_to_bottom(stacks->stack_b);
		single_swap(stacks->stack_b);
		single_rotate_bottom_to_top(stacks->stack_b);
		single_swap(stacks->stack_b);
	}
}

static void	smallest_first(t_stacks *stacks, t_sort *sort)
{
	if (sort->second < sort->third)
	{
		single_swap(stacks->stack_b);
		single_rotate_top_to_bottom(stacks->stack_b);
		single_swap(stacks->stack_b);
		single_rotate_bottom_to_top(stacks->stack_b);
		single_swap(stacks->stack_b);
	}
	else if (sort->second > sort->third)
	{
		single_swap(stacks->stack_b);
		push(stacks->stack_b, stacks->stack_a);
		sort->index--;
		single_swap(stacks->stack_b);
	}
}

void	sort_three_at_top_b(t_stacks *stacks)
{
	t_sort	sort;

	if (stacks)
	{
		sort.first = stacks->stack_b->top->value;
		sort.second = stacks->stack_b->top->prev->value;
		sort.third = stacks->stack_b->top->prev->prev->value;
		sort.index = 3;
		if (sort.first < sort.second && sort.first < sort.third)
			smallest_first(stacks, &sort);
		else if ((sort.first < sort.second && sort.first > sort.third) \
			|| (sort.first > sort.second && sort.first < sort.third))
			average_first(stacks, &sort);
		else if (sort.first > sort.second && sort.first > sort.third)
			bigger_first(stacks, &sort);
		while (sort.index-- > 0)
			push(stacks->stack_b, stacks->stack_a);
	}
}
