/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_ascending.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:43:51 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/09 18:49:31 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	is_sorted_asceding(t_stack *stack)
{
	t_node	*aux;

	if (!stack || stack->size == 0)
		return (1);
	aux = stack->top;
	while (aux->prev)
	{
		if (aux->value > aux->prev->value)
			return (0);
		aux = aux->prev;
	}
	return (1);
}
