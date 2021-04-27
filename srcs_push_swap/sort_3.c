/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:47:50 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/27 18:19:54 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **st)
{
	t_stack	*last;
	int		sec;

	sec = (*st)->next->num;
	last = last_element(*st);
	if ((*st)->num > sec && last->num > sec && (*st)->num > last->num)
		ra(st, 0);
	else if ((*st)->num < sec && last->num < sec && (*st)->num < last->num)
	{
		rra(st, 0);
		sa(st, 0);
	}
	else if ((*st)->num < sec && last->num < sec && (*st)->num > last->num)
		rra(st, 0);
	else if ((*st)->num > sec && sec > last->num)
	{
		sa(st, 0);
		rra(st, 0);
	}
	else if ((*st)->num > sec && sec < last->num && last->num > (*st)->num)
		sa(st, 0);
}
