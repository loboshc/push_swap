/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:38:40 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/13 10:57:22 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*aux;
	t_stack	*aux_2;

	if (stack_len(*stack_a) > 0)
	{
		aux = last_element(*stack_a); // aux guarda la dirrecion de memoria del ultimo elemento
		aux_2 = (*stack_a)->next; // aux_2 guarda la direccion de memoria del segundo elemento
		(*stack_a)->next = NULL; // el ultimo elemento apunta a NULL
		aux->next = *stack_a; // el ultimo elemento apunta al primero, combirtiendo al primero en ultimo 
		*stack_a = aux_2; // La cabeza apunta al segundo elemento combiertiendolo en el primero
	}
	printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*aux_2;

	if (stack_len(*stack_b) > 0)
	{
		aux = last_element(*stack_b); // aux guarda la dirrecion de memoria del ultimo elemento
		aux_2 = (*stack_b)->next; // aux_2 guarda la direccion de memoria del segundo elemento
		(*stack_b)->next = NULL; // el ultimo elemento apunta a NULL
		aux->next = *stack_b; // el ultimo elemento apunta al primero, combirtiendo al primero en ultimo 
		*stack_b = aux_2; // La cabeza apunta al segundo elemento combiertiendolo en el primero
	}
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}