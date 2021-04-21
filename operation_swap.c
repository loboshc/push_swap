/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:11:26 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/22 00:42:29 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack, int call)
{
	t_stack *aux;

	if (stack_len(*stack) > 1)
	{
		aux = (*stack)->next; // aux apunta al segundo elemendo
		(*stack)->next = aux->next; // el puntero del primer elemento apunta al tercero
		aux->next = *stack; // el puntero next auxiliar(que es el segundo elemento) apunta al primero
		*stack = aux; // la cabeza de lista apunta al segundo elemento
		if (call == 0) // si lo llama push_swap imprime
			printf("sa\n");
	}
}

void	sb(t_stack **stack, int call)
{
	t_stack *aux;

	if (stack_len(*stack) > 1)
	{
		aux = (*stack)->next; // aux apunta al segundo elemendo
		(*stack)->next = aux->next; // el puntero del primer elemento apunta al tercero
		aux->next = *stack; // el puntero next auxiliar(que es el segundo elemento) apunta al primero
		*stack = aux; // la cabeza de lista apunta al segundo elemento
		if (call == 0)
			printf("sb\n");
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b, int call)
{
	sa(stack_a, call);
	sb(stack_b, call);
}