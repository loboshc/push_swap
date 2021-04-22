/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:35:35 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/22 23:18:01 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	pa(t_stack **stack_a, t_stack **stack_b, int call)
{
	t_stack	*aux;
	t_stack	*aux_2;

	if (stack_len(*stack_b) > 0)
	{
		aux_2 = *stack_b;
		aux = (*stack_b)->next;
		(*stack_b)->next = *stack_a;
		*stack_b = aux;
		*stack_a = aux_2;
		if (call == 0)
			printf("pa\n");
	}
}

void	pb(t_stack **stack_b, t_stack **stack_a, int call)
{
	t_stack	*aux;
	t_stack	*aux_2;

	if (stack_len(*stack_a) > 0)
	{
		aux_2 = *stack_a;
		aux = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_a = aux;
		*stack_b = aux_2;
		if (call == 0)
			printf("pb\n");
	}
}
