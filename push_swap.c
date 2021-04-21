/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:28:38 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/21 15:52:06 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	get_min(t_stack **stack)
{
	t_stack	*aux;
	int	min;

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

int	get_max_pos(t_stack **stack)
{
	t_stack	*aux;
	int	max;

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

int	main(int argc, char *argv[])
{
	t_stack *h_stack_a;
	t_stack *h_stack_b;

	h_stack_a = NULL;
	h_stack_b = NULL;
	
	if (argc > 2)
	{
		check_arg(argc, argv);
		load_stack(&h_stack_a, argc, argv);
		//print_stack(h_stack_a, 'a');
		if (is_sorted(h_stack_a) == 0)
			exit(0);
		if (stack_len(h_stack_a) == 3 || stack_len(h_stack_a) == 2)
			sort_3(&h_stack_a);
		/*else if (stack_len(h_stack_a) > 3 && stack_len(h_stack_a) < 100)
			sort_min(&h_stack_a, &h_stack_b);*/
		else
			long_sort(argv, argc, &h_stack_a, &h_stack_b);
		//load_stack(&h_stack_b, argc, argv);
	}
	//print_stack(h_stack_a, 'a');
	//print_stack(h_stack_b, 'b');
	//sa(&h_stack_a);
	//sb(&h_stack_b);
	//ss(&h_stack_a, &h_stack_b);
	//pa(&h_stack_a, &h_stack_b);
	//pb(&h_stack_b, &h_stack_a);
	//pb(&h_stack_b, &h_stack_a);
	//pb(&h_stack_b, &h_stack_a);
	//ra(&h_stack_a);
	//rb(&h_stack_b);
	//rr(&h_stack_a, &h_stack_b);
	//rra(&h_stack_a);
	//rrb(&h_stack_b);
	//rrr(&h_stack_a, &h_stack_b);
	//sort_3(&h_stack_a);
	//print_stack(h_stack_a, 'a');
	//print_stack(h_stack_b, 'b');
	//printf("len stack_a %d\n", stack_len(h_stack_a));

	return (0);
}

// gcc push_swap.c check_arg.c utils.c utils_stack.c operation_swap.c operation_push.c operation_rotate.c operation_reverse_rotate.c algo.c long_algo.c