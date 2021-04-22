/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:18:21 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/22 23:19:34 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rra(t_stack **stack_a, int call)
{
	t_stack	*aux;
	t_stack	*aux_2;

	if (stack_len(*stack_a) > 0)
	{
		aux_2 = *stack_a;
		aux = last_element(*stack_a);
		while (aux_2->next != aux)
			aux_2 = aux_2->next;
		aux_2->next = NULL;
		aux->next = *stack_a;
		*stack_a = aux;
		if (call == 0)
			printf("rra\n");
	}
}

void	rrb(t_stack **stack_b, int call)
{
	t_stack	*aux;
	t_stack	*aux_2;

	if (stack_len(*stack_b) > 0)
	{
		aux_2 = *stack_b;
		aux = last_element(*stack_b);
		while (aux_2->next != aux)
			aux_2 = aux_2->next;
		aux_2->next = NULL;
		aux->next = *stack_b;
		*stack_b = aux;
		if (call == 0)
			printf("rrb\n");
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int call)
{
	rra(stack_a, call);
	rrb(stack_b, call);
}
