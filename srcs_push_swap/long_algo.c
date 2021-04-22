/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:13:12 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/22 23:26:51 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_next_item(t_stack *st_a, int len_a, int len_chunk)
{
	t_stack	*aux;
	int		pos;

	aux = st_a;
	pos = 0;
	while (aux != NULL)
	{
		if (aux->pos >= (len_a - len_chunk))
		{
			if (pos >= (len_a / 2))
				return (1);
		}
		pos++;
		aux = aux->next;
	}
	return (0);
}

void	create_chunk(t_stack **st_a, t_stack **st_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(*st_a) - 1;
	len_b = stack_len(*st_b);
	while (stack_len(*st_b) - len_b <= (len_a / 5))
	{
		if ((*st_a)->pos >= (len_a - (len_a / 5)))
			pb(st_b, st_a, 0);
		else
		{
			if (search_next_item(*st_a, len_a, (len_a / 5)) == 0)
			{
				while ((*st_a)->pos < (len_a - (len_a / 5)))
					ra(st_a, 0);
			}
			else
				while ((*st_a)->pos < (len_a - (len_a / 5)))
					rra(st_a, 0);
		}
	}
}

void	long_sort(char **argv, int argc, t_stack **st_a, t_stack **st_b)
{
	if (find_pos(st_a, argc, argv) == 1)
		exit_error("Error\n");
	while (stack_len(*st_a) >= 5)
		create_chunk(st_a, st_b);
	while ((*st_a)->pos != 3)
		ra(st_a, 0);
	pb(st_b, st_a, 0);
	sort_3(st_a);
	return_greater_to_a(st_a, st_b);
	while (is_sorted(*st_a) == 1)
		rra(st_a, 0);
}
