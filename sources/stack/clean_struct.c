/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:33:08 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 02:34:05 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	clean_struct(t_stacks *stacks)
{
	stack_clean(stacks->stack_a);
	stack_clean(stacks->stack_b);
	free(stacks);
}
