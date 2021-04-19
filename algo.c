/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:41:33 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/19 18:45:01 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **st)
{
	t_stack	*last;
	int		sec;

	sec = (*st)->next->num;
	last = last_element(*st);
	if (stack_len(*st) == 2 && (*st)->num > sec)
		sa(st);
	else if ((*st)->num > sec && last->num > sec && (*st)->num > last->num)
		ra(st);
	else if ((*st)->num < sec && last->num < sec && (*st)->num < last->num)
	{
		rra(st);
		sa(st);
	}
	else if ((*st)->num < sec && last->num < sec && (*st)->num > last->num)
		rra(st);
	else if ((*st)->num > sec && sec > last->num)
	{
		sa(st);
		rra(st);
	}
	else if ((*st)->num > sec && sec < last->num && last->num > (*st)->num)
		sa(st);
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
	
	//Buscar el mas pequeño, y cuando lo tenga enviarlo a stack_b
	while (stack_len(*st_a) > 3)
	{
		min = get_min(st_a);
		pos = get_pos(*st_a, min);
		while ((*st_a)->num != min)
		{
			if (pos < stack_len(*st_a) / 2)
				ra(st_a);
			else
				rra(st_a);
		}
		pb(st_b, st_a);
	}
	sort_3(st_a);
	while (stack_len(*st_b) > 0)
		pa(st_a, st_b);
}
