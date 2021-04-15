/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:18:21 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/15 01:57:34 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*aux;
	t_stack	*aux_2;

	if (stack_len(*stack_a) > 0)
	{
		aux_2 = *stack_a; // direccion de memoria del primer nodo
		aux = last_element(*stack_a);// guardo la direccion de memoria del ultimo elemento
		while (aux_2->next != aux) // busco la penultima posicion y cambio el puntero a NULL
			aux_2 = aux_2->next;
		aux_2->next = NULL;
		aux->next = *stack_a; // el puntero del ultimo elemento apunta al primero 
		*stack_a = aux; // la cabeza apunta a la dirrecion de memoria del ultimo elemento
		printf("rra\n");
	}
}

void	rrb(t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*aux_2;

	if (stack_len(*stack_b) > 0)
	{
		aux_2 = *stack_b; // direccion de memoria del primer nodo
		aux = last_element(*stack_b);// guardo la direccion de memoria del ultimo elemento
		while (aux_2->next != aux) // busco la penultima posicion y cambio el puntero a NULL
			aux_2 = aux_2->next;
		aux_2->next = NULL;
		aux->next = *stack_b; // el puntero del ultimo elemento apunta al primero 
		*stack_b = aux; // la cabeza apunta a la dirrecion de memoria del ultimo elemento
		printf("rrb\n");
	}
}

void rrr(t_stack **stack_a, t_stack ** stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}