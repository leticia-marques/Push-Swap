/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_sort_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:40:06 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 21:00:39 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	sort(t_stacks *stacks, int block_size)
{
	if (block_size == 1)
		push(stacks->stack_b, stacks->stack_a);
	else if (block_size == 2)
		sort_two_at_top_b(stacks);
	else if (block_size == 3)
		sort_three_at_top_b(stacks);
}

static void	push_middle(t_stacks *stacks, int *rotation_count, \
						int *block_size, int middle)
{
	push(stacks->stack_b, stacks->stack_a);
	if (stacks->stack_b->top->value < middle && *block_size > 0)
	{
		double_rotate_top_to_bottom(stacks);
		(*rotation_count)++;
		(*block_size)--;
	}
	else
		single_rotate_top_to_bottom(stacks->stack_a);
}

static int	send_block(t_stacks *stacks, int block_size, int middle, \
	int *pushed_back_count)
{
	int	rotation_count;

	rotation_count = 0;
	*pushed_back_count = 0;
	while (block_size-- > 0)
	{
		if (stacks->stack_b->top->value > middle)
		{
			push(stacks->stack_b, stacks->stack_a);
			(*pushed_back_count)++;
		}
		else if (stacks->stack_b->top->value == middle)
			push_middle(stacks, &rotation_count, &block_size, middle);
		else
		{
			single_rotate_top_to_bottom(stacks->stack_b);
			rotation_count++;
		}
	}
	return (rotation_count);
}

void	recursion_sort_b(t_stacks *stacks, int block_size, int rotated)
{
	int	middle;
	int	index;
	int	rotation_count;
	int	pushed_back_count;

	if (block_size < 4)
	{
		sort(stacks, block_size);
		return ;
	}
	middle = get_average_num(stacks->stack_b, block_size, 1);
	rotation_count = send_block(stacks, block_size, middle, &pushed_back_count);
	recursion_sort_a(stacks, pushed_back_count, 1);
	double_rotate_bottom_to_top(stacks);
	index = 1;
	if (rotated == 1)
	{
		while (index++ < rotation_count)
			single_rotate_bottom_to_top(stacks->stack_b);
	}
	recursion_sort_b(stacks, rotation_count, rotated);
}
