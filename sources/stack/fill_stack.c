/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:35:30 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 02:35:55 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	fill_stack(char **argv, int argc, t_stacks *stacks)
{
	while (argc-- > 1)
	{
		if (ft_strlen(argv[argc]) < 11)
			add_node(stacks->stack_a, ft_atoi(argv[argc]));
		else
		{
			stack_clean(stacks->stack_b);
			stack_clean(stacks->stack_b);
			free(stacks);
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
	}
}
