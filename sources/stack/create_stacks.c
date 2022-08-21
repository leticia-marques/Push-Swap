/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:26:53 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 17:42:48 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stacks	*create_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (0);
	stacks->stack_a = stack_create('a');
	if (!stacks->stack_a)
	{
		free(stacks);
		return (0);
	}
	stacks->stack_b = stack_create('b');
	if (!stacks->stack_b)
	{
		stack_clean(stacks->stack_a);
		free(stacks);
		return (0);
	}
	return (stacks);
}
