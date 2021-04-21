/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:35:35 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/21 20:54:16 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//tomar el top de b y ponerlo en el top de a. No hacer nada si b está vacío.
void	pa(t_stack **stack_a, t_stack **stack_b, int call)
{
	t_stack *aux;
	t_stack *aux_2;
	

	if (stack_len(*stack_b) > 0)
	{
		aux_2 = *stack_b; // guardo la direccion de memoria del primer elemento de b
		aux = (*stack_b)->next; // guardo la direccion de memoria del segundo elemento del stack b
		(*stack_b)->next = *stack_a; // asigno al apuntador next del primer elemento de b la direccion de memoria del top a
		*stack_b = aux; // top de b apunta al segundo elemento combirtiendose en el primero de top b
		*stack_a = aux_2; // top de a apunta al top de b combirtiendose en el primero de top de a
		if (call == 0)
			printf("pa\n");	
	}
}

//tomar el top de a y ponerlo en el top de b. No hacer nada si a está vacío.
void	pb(t_stack **stack_b, t_stack **stack_a, int call)
{
	t_stack *aux;
	t_stack *aux_2;

	if (stack_len(*stack_a) > 0)
	{
		aux_2 = *stack_a; // guardo la direccion de memoria del primer elemento de a
		aux = (*stack_a)->next; // aux apunta al segundo elemento del stack a
		(*stack_a)->next = *stack_b; // el puntero next del top de a apunta al top de b
		*stack_a = aux; // top de a apunta al segundo elemento
		*stack_b = aux_2; // top de b apunta al top de a
		if (call == 0)
			printf("pb\n");
	}
}
