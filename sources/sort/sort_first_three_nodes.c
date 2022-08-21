/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_first_three_nodes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:53:51 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 17:02:56 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_two_at_top(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->stack_a->top->value > stacks->stack_a->top->prev->value)
			single_swap(stacks->stack_a);
	}
}

static void	smallest_first(t_stacks *stacks, t_sort *sort)
{
	if (sort->first < sort->second \
		&& sort->second > sort->third \
		&& sort->third > sort->first)
	{
		single_rotate_top_to_bottom(stacks->stack_a);
		single_swap(stacks->stack_a);
		single_rotate_bottom_to_top(stacks->stack_a);
	}
}

static void	average_first(t_stacks *stacks, t_sort *sort)
{
	if (sort->second > sort->third)
	{
		single_rotate_top_to_bottom(stacks->stack_a);
		single_swap(stacks->stack_a);
		single_rotate_bottom_to_top(stacks->stack_a);
		single_swap(stacks->stack_a);
	}
	else if (sort->second < sort->third)
	{
		single_swap(stacks->stack_a);
	}
}

static void	bigger_first(t_stacks *stacks, t_sort *sort)
{
	if (sort->second < sort->third)
	{
		single_swap(stacks->stack_a);
		single_rotate_top_to_bottom(stacks->stack_a);
		single_swap(stacks->stack_a);
		single_rotate_bottom_to_top(stacks->stack_a);
	}
	else if (sort->second > sort->third)
	{
		single_swap(stacks->stack_a);
		single_rotate_top_to_bottom(stacks->stack_a);
		single_swap(stacks->stack_a);
		single_rotate_bottom_to_top(stacks->stack_a);
		single_swap(stacks->stack_a);
	}
}

void	sort_three_nodes(t_stacks *stacks)
{
	t_sort	sort;

	sort.first = stacks->stack_a->top->value;
	sort.second = stacks->stack_a->top->prev->value;
	sort.third = stacks->stack_a->top->prev->prev->value;
	if (sort.first > sort.second && sort.first > sort.third)
		bigger_first(stacks, &sort);
	else if ((sort.first < sort.second && sort.first > sort.third) \
		|| (sort.first > sort.second && sort.first < sort.third))
		average_first(stacks, &sort);
	else if (sort.first < sort.second && sort.first < sort.third)
		smallest_first(stacks, &sort);
}
