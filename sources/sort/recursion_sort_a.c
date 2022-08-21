/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_sort_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:02:11 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 18:07:33 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	sort(t_stacks *stacks, int block_size)
{
	if (block_size == 2)
		sort_two_at_top(stacks);
	else if (block_size == 3)
		sort_three_nodes(stacks);
}

static int	push_middle(t_stacks *stacks, int *rotation_count, int middle)
{
	push(stacks->stack_a, stacks->stack_b);
	if (stacks->stack_a->top->value > middle)
	{
		double_rotate_top_to_bottom(stacks);
		(*rotation_count)++;
	}
	else
		single_rotate_top_to_bottom(stacks->stack_b);
	return (1);
}

static int	send_block(t_stacks *stacks, int send_block, int middle, \
	int rotated)
{
	int	rotation_count;
	int	middle_moved;
	int	less_three;

	rotation_count = 0;
	middle_moved = 0;
	less_three = send_block < 3;
	while (send_block > 0)
	{
		if (stacks->stack_a->top->value < middle)
		{
			push(stacks->stack_a, stacks->stack_b);
			send_block--;
		}
		else if (!less_three && stacks->stack_a->top->value == middle)
			middle_moved = push_middle(stacks, &rotation_count, middle);
		else
		{
			single_rotate_top_to_bottom(stacks->stack_a);
			rotation_count++;
		}
	}
	while (rotated != 0 && rotation_count-- > 0)
		single_rotate_bottom_to_top(stacks->stack_a);
	return (middle_moved);
}

void	recursion_sort_a(t_stacks *stacks, int block_size, int rotated)
{
	int	send_size;
	int	middle;
	int	middle_moved;

	if (block_size < 4)
	{
		sort(stacks, block_size);
		return ;
	}
	if ((block_size % 2) == 0)
		send_size = (block_size / 2);
	else
		send_size = ((block_size / 2) + 1);
	middle = get_average_num(stacks->stack_a, block_size, 0);
	middle_moved = send_block(stacks, send_size, middle, rotated);
	recursion_sort_a(stacks, (block_size - send_size - middle_moved), rotated);
	if (middle_moved != 0 && stacks->stack_b->begin->value == middle)
	{
		single_rotate_bottom_to_top(stacks->stack_b);
		push(stacks->stack_b, stacks->stack_a);
	}
	if (send_size != stacks->stack_b->size)
		recursion_sort_b(stacks, send_size, 1);
	else
		recursion_sort_b(stacks, send_size, 0);
}
