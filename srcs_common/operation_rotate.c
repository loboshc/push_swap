/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:38:40 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/22 23:21:00 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ra(t_stack **stack_a, int call)
{
	t_stack	*aux;
	t_stack	*aux_2;

	if (stack_len(*stack_a) > 0)
	{
		aux = last_element(*stack_a);
		aux_2 = (*stack_a)->next;
		(*stack_a)->next = NULL;
		aux->next = *stack_a;
		*stack_a = aux_2;
		if (call == 0)
			printf("ra\n");
	}
}

void	rb(t_stack **stack_b, int call)
{
	t_stack	*aux;
	t_stack	*aux_2;

	if (stack_len(*stack_b) > 0)
	{
		aux = last_element(*stack_b);
		aux_2 = (*stack_b)->next;
		(*stack_b)->next = NULL;
		aux->next = *stack_b;
		*stack_b = aux_2;
		if (call == 0)
			printf("rb\n");
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b, int call)
{
	ra(stack_a, call);
	rb(stack_b, call);
}
