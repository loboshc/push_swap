/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:41:33 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/22 23:29:44 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack **stack)
{
	t_stack	*aux;
	int		min;

	min = INT_MAX;
	aux = *stack;
	while (aux != NULL)
	{
		if (aux->num < min)
			min = aux->num;
		aux = aux->next;
	}
	return (min);
}

int	get_pos(t_stack *stack, int find)
{
	int		len;
	t_stack	*aux;

	aux = stack;
	len = 0;
	while (aux->num != find)
	{
		aux = aux->next;
		len++;
	}
	return (len);
}

void	sort_min(t_stack **st_a, t_stack **st_b)
{
	int	min;
	int	pos;

	while (stack_len(*st_a) > 3)
	{
		min = get_min(st_a);
		pos = get_pos(*st_a, min);
		while ((*st_a)->num != min)
		{
			if (pos < stack_len(*st_a) / 2)
				ra(st_a, 0);
			else
				rra(st_a, 0);
		}
		pb(st_b, st_a, 0);
	}
	sort_3(st_a);
	while (stack_len(*st_b) > 0)
		pa(st_a, st_b, 0);
}
