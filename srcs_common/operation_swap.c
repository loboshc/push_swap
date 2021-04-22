/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:11:26 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/22 23:22:07 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sa(t_stack **stack, int call)
{
	t_stack	*aux;

	if (stack_len(*stack) > 1)
	{
		aux = (*stack)->next;
		(*stack)->next = aux->next;
		aux->next = *stack;
		*stack = aux;
		if (call == 0)
			printf("sa\n");
	}
}

void	sb(t_stack **stack, int call)
{
	t_stack	*aux;

	if (stack_len(*stack) > 1)
	{
		aux = (*stack)->next;
		(*stack)->next = aux->next;
		aux->next = *stack;
		*stack = aux;
		if (call == 0)
			printf("sb\n");
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b, int call)
{
	sa(stack_a, call);
	sb(stack_b, call);
}
