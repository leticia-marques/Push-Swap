/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:14:57 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 17:44:01 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	stack_clean(t_stack *stack)
{
	t_node	*aux;
	t_node	*tmp;

	if (!stack)
		return ;
	aux = stack->top;
	while (aux)
	{
		tmp = aux->prev;
		free(aux);
		aux = tmp;
	}
	free(stack);
}
