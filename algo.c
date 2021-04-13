/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:41:33 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/13 10:54:59 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **st)
{
	t_stack *last;
	int sec;

	sec = (*st)->next->num;
	last = last_element(*st);
	if ((*st)->num > sec && last->num > sec && (*st)->num > last->num) 
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