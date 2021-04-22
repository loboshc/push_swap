/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_greater_to_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:51:06 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/22 23:28:55 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_pos(t_stack **stack)
{
	t_stack	*aux;
	int		max;

	max = 0;
	aux = *stack;
	while (aux != NULL)
	{
		if (aux->pos > max)
			max = aux->pos;
		aux = aux->next;
	}
	return (max);
}

int	search_next_greater(t_stack *st_b, int max)
{
	t_stack	*aux;
	int		pos;
	int		len_b;

	aux = st_b;
	pos = 0;
	len_b = stack_len(st_b);
	while (aux != NULL)
	{
		if (aux->pos == max)
			if (pos > (len_b / 2))
				return (1);
		aux = aux->next;
		pos++;
	}
	return (0);
}

void	return_greater_to_a(t_stack **st_a, t_stack **st_b)
{
	int	max;

	while (stack_len(*st_b) > 0)
	{
		max = get_max_pos(st_b);
		if ((*st_b)->pos == max)
			pa(st_a, st_b, 0);
		else
		{
			if (search_next_greater(*st_b, max) == 1)
			{
				while ((*st_b)->pos != max)
					rrb(st_b, 0);
			}
			else
			{
				while ((*st_b)->pos != max)
					rb(st_b, 0);
			}
		}
	}
}
