/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:11:26 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/13 10:58:04 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack)
{
	t_stack *aux;

	if (stack_len(*stack) > 1)
	{
		aux = (*stack)->next; // aux apunta al segundo elemendo
		(*stack)->next = aux->next; // el puntero del primer elemento apunta al tercero
		aux->next = *stack; // el puntero next auxiliar(que es el segundo elemento) apunta al primero
		*stack = aux; // la cabeza de lista apunta al segundo elemento
	}
	printf("sa\n");
}

void	sb(t_stack **stack)
{
	t_stack *aux;

	if (stack_len(*stack) > 1)
	{
		aux = (*stack)->next; // aux apunta al segundo elemendo
		(*stack)->next = aux->next; // el puntero del primer elemento apunta al tercero
		aux->next = *stack; // el puntero next auxiliar(que es el segundo elemento) apunta al primero
		*stack = aux; // la cabeza de lista apunta al segundo elemento
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}