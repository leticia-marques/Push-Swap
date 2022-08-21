/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:37:23 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 20:58:15 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	call_algo(t_stacks *stacks, int size)
{
	if (!is_sorted_asceding(stacks->stack_a))
	{
		if (size == 3)
			sort_three_nodes_stack(stacks->stack_a);
		else if (size == 4)
			sort_four_nodes_stack(stacks);
		else if (size == 5)
			sort_five_nodes_stack(stacks->stack_a, stacks->stack_b);
		else
			recursion_sort_a(stacks, stacks->stack_a->size, 0);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	check_arguments(argv, argc);
	if (argc < 2)
		return (0);
	stacks = create_stacks();
	fill_stack(argv, argc, stacks);
	call_algo(stacks, stacks->stack_a->size);
	clean_struct(stacks);
}
