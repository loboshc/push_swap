/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:28:38 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/09 20:27:48 by dlobos-m         ###   ########.fr       */
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

void	load_stack(t_stack **stack, int argc, char **argv)
{
	int i = argc - 1;
	argv++;
	while (i-- > 0)
		add_element(stack, ft_number(argv[i]));
}

int	sa(t_stack **stack)
{
	t_stack *aux;

	if (stack_len(*stack) > 1)
	{
		aux = (*stack)->next; // aux apunta al segundo elemendo
		(*stack)->next = aux->next; // el puntero del primer elemento apunta al tercero
		aux->next = *stack; // el puntero next auxiliar(que es el segundo elemento) apunta al primero
		*stack = aux; // la cabeza de lista apunta al segundo elemento
	}
	return (0);
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
	}
	print_stack(h_stack_a, 'a');
	sa(&h_stack_a);
	
	print_stack(h_stack_a, 'a');
	printf("len stack_a %d\n", stack_len(h_stack_a));
	print_stack(h_stack_b, 'b');
	return (0);
}