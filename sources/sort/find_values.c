/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 03:47:17 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 02:44:58 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	find_smallest(t_stack *stack)
{
	t_node	*aux;
	int		i;

	aux = stack->top;
	i = aux->value;
	while (aux != NULL)
	{
		if (aux->value < i)
			i = aux->value;
		aux = aux->prev;
	}
	return (i);
}

int	find_highest(t_stack *stack)
{
	t_node	*aux;
	int		i;

	aux = stack->top;
	i = aux->value;
	while (aux)
	{
		if (aux->value > i)
			i = aux->value;
		aux = aux->prev;
	}
	return (i);
}
