/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:28:38 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/11 19:23:47 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arg(int argc, char *argv[])
{
	int	i;
	int	tmp;
	int	j;

	i = -1;
	argv++;
	while (++i < argc - 1)
	{
		if (*argv[i] == '-' && (argv[i][1] == '0' || argv[i][1] == '\0'))
			exit_error("Error\nInvalid arguments\n");
		tmp = ft_number(argv[i]);
		j = i;
		while (argc > --j && j >= 0)
		{
			if (tmp == ft_number(argv[j]))
				exit_error("Error\nRepeated number\n");
		}
	}
}

int	main(int argc, char *argv[])
{
	t_stack *h_stack_a;
	t_stack *h_stack_b;

	h_stack_a = NULL;
	h_stack_b = NULL;
	if (argc > 1)
	{
		check_arg(argc, argv);
		load_stack(&h_stack_a, argc, argv);
		load_stack(&h_stack_b, argc, argv);
	}
	print_stack(h_stack_a, 'a');
	print_stack(h_stack_b, 'b');
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
	rrr(&h_stack_a, &h_stack_b);
	print_stack(h_stack_a, 'a');
	print_stack(h_stack_b, 'b');
	//printf("len stack_a %d\n", stack_len(h_stack_a));
	return (0);
}

// gcc push_swap.c utils.c utils_stack.c operation_swap.c operation_push.c