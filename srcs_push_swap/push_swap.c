/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:28:38 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/27 20:22:06 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*h_stack_a;
	t_stack	*h_stack_b;

	h_stack_a = NULL;
	h_stack_b = NULL;
	check_arg(argc, argv, 0);
	if (argc > 2)
	{
		load_stack(&h_stack_a, argc, argv, 0);
		if (is_sorted(h_stack_a) == 0)
			exit(0);
		if (stack_len(h_stack_a) == 2 && h_stack_a->num > h_stack_a->next->num)
			sa(&h_stack_a, 0);
		else if (stack_len(h_stack_a) == 3)
			sort_3(&h_stack_a);
		else if (stack_len(h_stack_a) > 3 && stack_len(h_stack_a) < 100)
			sort_min(&h_stack_a, &h_stack_b);
		else
			long_sort(argv, argc, &h_stack_a, &h_stack_b);
	}
	free_stack(h_stack_a);
	free_stack(h_stack_b);
	return (0);
}
